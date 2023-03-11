/**
* @file BinarySearchTree.hpp
* @description BinarySearchTree class inin header i
* @course Kayhan Ayar 1/C
* @assignment odev2
* @date 12/21/2022
* @author emre kara emre.kara11@ogr.sakarya.edu.tr
*/


#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp
#include "Tissue.hpp"
#include <iostream>

class BinarySearchTree {
public:
	BinarySearchTree();
    ~BinarySearchTree();
    void add(Tissue* tissue);
    Tissue** postOrder();
    Tissue* rootTissue;
    int tissueCount;
private:
    void m_recursivePostOrder(Tissue* tissue, Tissue** arr, int* i);
};
#endif 

