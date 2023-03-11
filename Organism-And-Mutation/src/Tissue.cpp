
#include "Tissue.hpp"

void Tissue::sort() {
    Radix* r = new Radix(m_arr, m_UsedSlotCount);
    delete r;
    midVal = m_arr[m_UsedSlotCount / 2]->val();
}

Tissue::Tissue() {
    Cell** arr = new Cell * [5];
    m_arr = arr;
    m_arrSize = 5;
    m_UsedSlotCount = 0;
    //********************
    midVal = 0;
    rightTissue = 0;
    leftTissue = 0;
}

void Tissue::mutate(){
    for(int i = 0; i < m_UsedSlotCount; i++)
        if(m_arr[i]->val() % 2 == 0)
            m_arr[i]->mutate();
    
} 

void Tissue::addCell(Cell* cell) {
    if (m_isFull()) m_expand();
    m_arr[m_UsedSlotCount] = cell;
    m_UsedSlotCount++;
}
void Tissue::m_expand() {
    m_arrSize += 5;
    Cell** arr = new Cell * [m_arrSize];
    for (int i = 0; i < m_UsedSlotCount; i++)
        arr[i] = m_arr[i];
    delete[] m_arr;
    m_arr = arr;
}


bool Tissue::m_isFull() {
    if (m_arrSize == m_UsedSlotCount) return true;
    return false;
}

Tissue::~Tissue() {
    for (int i = 0; i < m_UsedSlotCount; i++)
    {
        delete m_arr[i];
    }
    if (rightTissue != 0) delete rightTissue;
    if (leftTissue != 0) delete leftTissue;
    delete[] m_arr;
}











