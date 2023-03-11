/**
* @file Organism.hpp
* @description Organism class inin header i
* @course Kayhan Ayar 1/C
* @assignment odev2
* @date 12/21/2022
* @author emre kara emre.kara11@ogr.sakarya.edu.tr
*/


#ifndef Organism_hpp
#define Organism_hpp
#include "System.hpp"

class Organism {
public:
	Organism();
    ~Organism();
	void add(System *system);
    void print();
    void mutate();
private:
    System** m_systemArr;
    void m_expand();
    int m_index;
    int m_arrSize;
};

#endif 