/**
* @file Organ.hpp
* @description Organ class inin header i
* @course Kayhan Ayar 1/C
* @assignment odev2
* @date 12/21/2022
* @author emre kara emre.kara11@ogr.sakarya.edu.tr
*/


#ifndef Organ_hpp
#define Organ_hpp
#include "BinarySearchTree.hpp"
#include "AVLCheck.hpp"

class Organ {
public:
	Organ();
    ~Organ();
	void add(Tissue *tissue);
    void print();
    void mutate();
    int getRootVal();
private:
    BinarySearchTree *m_bst;
};

#endif 