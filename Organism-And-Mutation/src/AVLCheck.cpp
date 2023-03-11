
#include "AVLCheck.hpp"


AVLCheck::AVLCheck() {}
AVLCheck::~AVLCheck() {}

bool AVLCheck::check(BinarySearchTree* bst) {
    if (m_recursiveCheck(bst->rootTissue) == -1) return false;
    return true;
}

int AVLCheck::m_recursiveCheck(Tissue* tissue) {
    if (tissue) {
        int l = m_recursiveCheck(tissue->leftTissue),
            r = m_recursiveCheck(tissue->rightTissue);
        if ((l == -1) || (r == -1) || (abs(r - l) > 1)) return -1;
        if (r < l) return (l + 1);
        return (r + 1);
    }
    return 0;
}