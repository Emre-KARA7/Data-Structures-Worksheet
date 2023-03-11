
#include "Organ.hpp"


Organ::Organ() {
    BinarySearchTree* bst = new BinarySearchTree();
    m_bst = bst;
}
Organ::~Organ() {
    delete m_bst;
}

int Organ::getRootVal(){
    return m_bst->rootTissue->midVal;
}
void Organ::mutate(){
    if((getRootVal() % 50) == 0){

        Tissue** t = m_bst->postOrder();
        m_bst->rootTissue = 0;
        delete m_bst;
        BinarySearchTree* bst = new BinarySearchTree();
        m_bst = bst;

        for(int i = 0; i < 20; i++){
            t[i]->mutate();
            t[i]->sort();
            t[i]->rightTissue = 0;
            t[i]->leftTissue = 0;
            add(t[i]);
        }   
        
        delete[] t;
    }
}

void Organ::print() {
    AVLCheck* avl = new AVLCheck();
    if (avl->check(m_bst)) std::cout << " ";
    else std::cout << "#";
    delete avl;
}
void Organ::add(Tissue* tissue) {
    m_bst->add(tissue);
}