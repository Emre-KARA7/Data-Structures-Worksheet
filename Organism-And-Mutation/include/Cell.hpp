/**
* @file Cell.hpp
* @description Cell class inin header i
* @course Kayhan Ayar 1/C
* @assignment odev2
* @date 12/21/2022
* @author emre kara emre.kara11@ogr.sakarya.edu.tr
*/


#ifndef Cell_hpp
#define Cell_hpp
class Cell {
public:
	Cell();
	void cellSet(int data);
	int val();
	void mutate();
private:
	int m_data;
};
#endif 