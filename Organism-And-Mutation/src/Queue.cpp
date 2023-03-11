

#include "Queue.hpp"
#include <iostream>
Queue::Queue() {
    m_arraySize = 0;
    m_dataCount = 0;
    m_frontIndex = 0;
    m_backIndex = 0;
    m_datas = 0;
}

void Queue::push(Cell* data) {
    if (m_dataCount == m_arraySize) expand();
    m_backIndex = (m_backIndex + 1) % m_arraySize;
    m_datas[m_backIndex] = data;
    m_dataCount++;
}


void Queue::pop() {
    if (m_dataCount != 0) {
        m_frontIndex = (m_frontIndex + 1) % m_arraySize;
        m_dataCount--;
    }
}

Cell* Queue::front() {
    if (m_dataCount != 0) return m_datas[m_frontIndex];
}

void Queue::expand(int amount, char mode) {
    int newSize = 0;
    if (mode == '%') newSize = (m_arraySize * 100) / amount + m_arraySize;
    else newSize = m_arraySize + amount; // mode '+'

    Cell** newArr = new Cell* [newSize];
    int preIndex = m_frontIndex;
    for (int i = 0; i < m_dataCount; i++) {
        newArr[i] = m_datas[preIndex];
        preIndex = (preIndex + 1) % m_arraySize;
    }
    if (m_dataCount != 0) delete[] m_datas;
    m_frontIndex = 0;
    m_backIndex = m_dataCount - 1;
    m_datas = newArr;
    m_arraySize = newSize;
}

bool Queue::empty() {
    if (m_dataCount == 0) return true;
    return false;
}

int Queue::size() {
    return m_dataCount;
}

void Queue::print() {
    int counter = 0, i = m_frontIndex;
    do {
        std::cout << "[" << i << "] : " << m_datas[i]->val() << std::endl;
        i++;
    } while (i != m_backIndex + 1);

}

Queue :: ~Queue() {
    delete[] m_datas;
}