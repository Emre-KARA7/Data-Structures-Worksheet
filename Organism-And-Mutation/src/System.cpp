

#include "System.hpp"

System::System() {
    Organ** organArr = new Organ * [100];
    m_organArr = organArr;
    m_index = 0;
}

System::~System() {
    for (int i = 0; i < m_index; i++)
        delete m_organArr[i];

    delete[] m_organArr;
}

void System::print() {
    for (int i = 0; i < m_index; i++) {
        m_organArr[i]->print();
    }
}

void System::mutate(){
    for(int i = 0; i < m_index; i++)
        m_organArr[i]->mutate();
}

void System::add(Organ* organ) {
    m_organArr[m_index] = organ;
    m_index++;
}