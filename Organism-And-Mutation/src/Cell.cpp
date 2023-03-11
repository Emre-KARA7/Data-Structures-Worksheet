
#include "Cell.hpp"
Cell::Cell() {
    m_data = 0;
}
int Cell::val() {
    return m_data;
}
void Cell::cellSet(int data) {
    m_data = data;
}
void Cell::mutate(){
    m_data = m_data / 2;
}