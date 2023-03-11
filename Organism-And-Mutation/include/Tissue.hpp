/**
* @file Tissue.hpp
* @description Tissue class inin header i
* @course Kayhan Ayar 1/C
* @assignment odev2
* @date 12/21/2022
* @author emre kara emre.kara11@ogr.sakarya.edu.tr
*/


#ifndef Tissue_hpp
#define Tissue_hpp
#include "Cell.hpp"
#include "Radix.hpp"
#include <iostream>
class Tissue {
public:
	Tissue();
    ~Tissue();
	void addCell(Cell *cell);
    void sort();
    void mutate();
    int midVal;
    Tissue *rightTissue;
    Tissue *leftTissue;
private:
    bool m_isFull();
    int m_arrSize;
    int m_UsedSlotCount;
    void m_expand();	
    Cell **m_arr;
};
#endif 