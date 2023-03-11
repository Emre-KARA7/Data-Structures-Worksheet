/**
* @file System.hpp
* @description System class inin header i
* @course Kayhan Ayar 1/C
* @assignment odev2
* @date 12/21/2022
* @author emre kara emre.kara11@ogr.sakarya.edu.tr
*/


#ifndef System_hpp
#define System_hpp
#include "Organ.hpp"

class System {
public:
	System();
    ~System();
	void add(Organ* organ);
    void print();
    void mutate();
private:
    Organ** m_organArr;
    int m_index;
};

#endif 