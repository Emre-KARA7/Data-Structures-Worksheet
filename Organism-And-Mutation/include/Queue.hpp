/**
* @file Queue.hpp
* @description Queue class inin header i
* @course Kayhan Ayar 1/C
* @assignment odev2
* @date 12/21/2022
* @author emre kara emre.kara11@ogr.sakarya.edu.tr
*/

#ifndef Queue_hpp
#define Queue_hpp
#include "Cell.hpp"

class Queue{
    public:
    Queue();
    ~Queue();
    void push(Cell* data);
    void pop();
    Cell* front();
    void expand(int amount = 5, char mode = '+');
    bool empty();
    int size();
    void print();
    
    private:
    int m_arraySize;
    int m_dataCount;
    int m_frontIndex;
    int m_backIndex;
    Cell** m_datas;
};

#endif