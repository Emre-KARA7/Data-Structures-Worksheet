
#include "Radix.hpp"
#include <iostream>
#include <cmath>
Radix::Radix(Cell** Cells, int size) {
    m_maxDigit = 0;
    for (int i = 0; i < size; i++) {
        if (m_maxDigit < calculateDigit(Cells[i]->val()))
            m_maxDigit = calculateDigit(Cells[i]->val());
    }
   
    Queue* queues = new Queue[10];
    for (int i = 0; i < m_maxDigit; i++) {
        for (int j = 0; j < size; j++) {
            int digit = m_pow(10, i + 1);
            queues[(Cells[j]->val() % digit) / m_pow(10, i)].push(Cells[j]);
        }
        int newArrIndex = 0;
        for (int k = 0; k < 10; k++) {
            while (!queues[k].empty()) {
                Cells[newArrIndex] = queues[k].front();
                queues[k].pop();
                newArrIndex++;
            }
        }
    }
    delete[] queues;
}

int Radix::calculateDigit(int number) {
    
    return int(log10(number) + 1);
}

int Radix::m_pow(int n, int p) {
    if (p == 0)return 1;
    int result = 1;
    for (int i = 0; i < p; i++)
    {
        result *= n;
    }
    return result;
}