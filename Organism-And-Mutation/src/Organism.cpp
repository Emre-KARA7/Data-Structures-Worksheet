

#include "Organism.hpp"
Organism::Organism() {
    m_index = 0;
    System** systemArr = new System * [5];
    m_systemArr = systemArr;
    m_arrSize = 5;
}

Organism::~Organism() {
    for (int i = 0; i < m_index; i++)
        delete m_systemArr[i];

    delete[] m_systemArr;
}

void Organism::add(System* system) {
    if (m_index + 1 == m_arrSize) m_expand();
    m_systemArr[m_index] = system;
    m_index++;
}

void Organism::print() {
    for (int i = 0; i < m_index; i++) {
        m_systemArr[i]->print();
        std::cout << std::endl;
    }
}

void Organism::m_expand() {
    m_arrSize += 5;
    System** systemArr = new System * [m_arrSize];
    for (int i = 0; i < m_index; i++)
        systemArr[i] = m_systemArr[i];
    delete[] m_systemArr;
    m_systemArr = systemArr;
}

void Organism::mutate(){
    for(int i = 0; i < m_index; i++)
        m_systemArr[i]->mutate();
}