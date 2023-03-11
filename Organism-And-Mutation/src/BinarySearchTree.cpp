
#include "BinarySearchTree.hpp"


BinarySearchTree::BinarySearchTree() {
    rootTissue = 0;
    tissueCount = 0;
}

BinarySearchTree::~BinarySearchTree() {
    delete rootTissue;
}

//***
Tissue** BinarySearchTree::postOrder() {
    Tissue** postOrderedTissues = new Tissue*[tissueCount];
    int i = 0;
    m_recursivePostOrder(rootTissue, postOrderedTissues, &i);
    return postOrderedTissues;
}

void BinarySearchTree::m_recursivePostOrder(Tissue* tissue, Tissue** arr, int* i) {
    if (tissue) {
        m_recursivePostOrder(tissue->leftTissue, arr, i);
        m_recursivePostOrder(tissue->rightTissue, arr, i);
        arr[*i] = tissue;
        *(i) += 1;
    }
}
//***

void BinarySearchTree::add(Tissue* tissue) {
    if (rootTissue == 0) rootTissue = tissue;
    else {
        Tissue* temp = rootTissue;
        while (true)
        {
            if (temp->midVal < tissue->midVal) { //right
                if (temp->rightTissue != 0) temp = temp->rightTissue;
                else {
                    temp->rightTissue = tissue;
                    break;
                }
            }
            else { //left
                if (temp->leftTissue != 0) temp = temp->leftTissue;
                else {
                    temp->leftTissue = tissue;
                    break;
                }
            }
        }
    }
    tissueCount++;
 
}