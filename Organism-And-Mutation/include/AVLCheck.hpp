/**
* @file AVLCheck.hpp
* @description AVLCheck class inin header i
* @course Kayhan Ayar 1/C
* @assignment odev2
* @date 12/21/2022
* @author emre kara emre.kara11@ogr.sakarya.edu.tr
*/

#ifndef AVLCheck_hpp
#define AVLCheck_hpp
#include "BinarySearchTree.hpp"
#include "Tissue.hpp"
#include <math.h>

class AVLCheck {
public:
	AVLCheck();
    ~AVLCheck();
    bool check(BinarySearchTree *bst);
private:
    int m_recursiveCheck(Tissue *tissue);
};
#endif 