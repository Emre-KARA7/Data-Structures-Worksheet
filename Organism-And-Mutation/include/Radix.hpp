/**
* @file Radix.hpp
* @description Radix class inin header i
* @course Kayhan Ayar 1/C
* @assignment odev2
* @date 12/21/2022
* @author emre kara emre.kara11@ogr.sakarya.edu.tr
*/

#ifndef Radix_hpp
#define Radix_hpp
#include "Cell.hpp"
#include "Queue.hpp"

class Radix{
    public:
    Radix(Cell **Cell, int size);
    void sort();
    private:
    int m_pow(int n, int p);
    int calculateDigit(int number);
    int m_size;
    int m_maxDigit;
};

#endif 