#include "YoneticiListesi.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>  
using namespace std;



YoneticiListesi::YoneticiListesi() {
	rowListCount = 0;
}
std::string YoneticiListesi::cast(int row, std::string type){
    if (-1< row <= rowListCount)
    {
        SatirListesi* temporaryRowList = firstRowList;
        for (int i = 0; i < row; i++)
        {
            temporaryRowList = temporaryRowList->nextRowList;
        }
        if (type == "this")
        {
            std::ostringstream oss;
            oss  << temporaryRowList;
            std::string s = oss.str();
            return s;
        }
        else if (type == "prev")
        {
            std::ostringstream oss;
            oss  << temporaryRowList->prevRowList;
            std::string s = oss.str();
            return s;
        }
        else if (type == "average")
        {
            temporaryRowList->average;
            std::ostringstream ss;
            ss << temporaryRowList->average;
            std::string s(ss.str());
            return s;
        }
        else if (type == "next")
        {
            std::ostringstream oss;
            oss  << temporaryRowList->nextRowList;
            std::string s = oss.str();
            return s;
        }
        else if (type == "nodeCount")
        {
            std::ostringstream oss;
            oss  << temporaryRowList->nodeCount;
            std::string s = oss.str();
            return s;
        }
        
    }
    
}
std::string YoneticiListesi::cast(int row, int index, std::string type){
    if (-1< row <= rowListCount)
    {
        SatirListesi* temporaryRowList = firstRowList;
        for (int i = 0; i < row; i++)
        {
            temporaryRowList = temporaryRowList->nextRowList;
        }
        if (-1 < index <= temporaryRowList->nodeCount)
        {
            Dugum* temporaryNode = temporaryRowList->firstNode;
            for (int i = 0; i < index; i++)
            {
                temporaryNode = temporaryNode->nextNode;
            }
            if (type == "this")
            {
                std::ostringstream oss;
                oss  << temporaryNode;
                std::string s = oss.str();
                return s;
            }
            else if (type == "data")
            {
                std::ostringstream ss;
                ss << temporaryNode->data;
                std::string s(ss.str());
                return s;
            }
            else if (type == "next")
            {
                std::ostringstream oss;
                oss  << temporaryNode->nextNode;
                std::string s = oss.str();
                return s;
            }
        }
        
    }
}
YoneticiListesi::~YoneticiListesi() {
    delete this->firstRowList;
    
}
int YoneticiListesi::delRandIndex(int RowIndex){
    srand (time(NULL));
    SatirListesi* temporaryRowList = firstRowList;
    for (int i = 0; i < RowIndex; i++)
    {
        temporaryRowList = temporaryRowList->nextRowList;
    }    
    int randVal=rand() % temporaryRowList->nodeCount;
    return randVal;
}
void YoneticiListesi::delRow(int RowIndex)
{
    SatirListesi* temporaryRowList = firstRowList;
    if (RowIndex==0)
    {
        if (rowListCount!=1)
		{
			firstRowList  = temporaryRowList->nextRowList;
		}
		else{
			firstRowList = 0;
		}
    }
    else{
        for (int i = 0; i < RowIndex-1; i++)
		{
			temporaryRowList = temporaryRowList->nextRowList;
		}
		SatirListesi* temporaryRowList2 = temporaryRowList;
		temporaryRowList = temporaryRowList->nextRowList;
		temporaryRowList2->nextRowList = temporaryRowList->nextRowList;
    }
    while (temporaryRowList->firstNode != 0)
    {
        temporaryRowList->deleteNode(0);
    }
    
    delete temporaryRowList;
    rowListCount--;
}
SatirListesi* YoneticiListesi::createRow(){
    SatirListesi* s = new SatirListesi();
    if (rowListCount == 0)
    {
        firstRowList = s;
    }
    else{
        SatirListesi* temporaryRowList = firstRowList;
        while (temporaryRowList->nextRowList != 0)//go to last row
        {
            temporaryRowList = temporaryRowList->nextRowList;
        }
        s->prevRowList = temporaryRowList;
        temporaryRowList->nextRowList = s;
    }
    rowListCount++;
    return s;
}
void YoneticiListesi::delRandNode(int RowIndex, int delRandIndex){
    SatirListesi* temporaryRowList = firstRowList;
    for (int i = 0; i < RowIndex; i++)
    {
        temporaryRowList = temporaryRowList->nextRowList;
    }    
    temporaryRowList->deleteNode(delRandIndex);
    if (temporaryRowList->firstNode == 0)
    {
        delRow(RowIndex);
    }
    else{
        temporaryRowList->calculateAverage();
        sort(temporaryRowList);
    }
}

void YoneticiListesi::addToRow(int val){
    Dugum* d = new Dugum(val);
    SatirListesi* temporaryRowList = firstRowList;
    while (temporaryRowList->nextRowList != 0)//go to last row
    {
        temporaryRowList = temporaryRowList->nextRowList;
    }
    //add node
    if (temporaryRowList->nodeCount == 0)//there is no node
    {
        temporaryRowList->firstNode = d;
        temporaryRowList->nodeCount++;
        temporaryRowList->calculateAverage();
        //sort(temporaryRowList);
    }
    else{
        Dugum* temporaryNode = temporaryRowList->firstNode;
        while (temporaryNode->nextNode != 0)
        {
            temporaryNode = temporaryNode->nextNode;
        }
        temporaryNode->nextNode = d;
        temporaryRowList->nodeCount++;
        temporaryRowList->calculateAverage();
    }
    //sort(temporaryRowList);
    
}

void YoneticiListesi::sort(SatirListesi* ptrRow){
    std::cout<<"enter ";
    while ( (ptrRow->prevRowList != 0) && ( ptrRow->prevRowList->average > ptrRow->average))
    {
        //switch (left)
        if (firstRowList == ptrRow->prevRowList) //first 
        {
            firstRowList = ptrRow;
            ptrRow->prevRowList->nextRowList = ptrRow->nextRowList;
            ptrRow->prevRowList->prevRowList = ptrRow;
            ptrRow->nextRowList = ptrRow->prevRowList;
            ptrRow->prevRowList = 0;
            if (ptrRow->nextRowList->nextRowList != 0)
            {
                ptrRow->nextRowList->nextRowList->prevRowList = ptrRow->nextRowList;
            }
        }
        else { 
            SatirListesi* copy = ptrRow->prevRowList->prevRowList;
            ptrRow->prevRowList->nextRowList = ptrRow->nextRowList;
            ptrRow->prevRowList->prevRowList = ptrRow;
            ptrRow->nextRowList = ptrRow->prevRowList;
            copy->nextRowList = ptrRow;
            ptrRow->prevRowList = copy;
            if (ptrRow->nextRowList->nextRowList != 0)//mid
            {
                ptrRow->nextRowList->nextRowList->prevRowList = ptrRow->nextRowList;
            }
            
        }
       
    }
  

    while ( ptrRow->nextRowList != 0 && ptrRow->average > ptrRow->nextRowList->average )
    {
        //switch (left)
        if (firstRowList == ptrRow){//first
            firstRowList = ptrRow->nextRowList;
            if (ptrRow->nextRowList->nextRowList != 0)//if there re more than 2 rows
            {
                ptrRow->nextRowList->nextRowList->prevRowList = ptrRow;
            }
            ptrRow->nextRowList->prevRowList = 0;
            ptrRow->prevRowList = firstRowList;
            ptrRow->nextRowList = ptrRow->nextRowList->nextRowList;
            firstRowList->nextRowList = ptrRow;
        }
        else{
            SatirListesi* copy = ptrRow->nextRowList->nextRowList;
            ptrRow->prevRowList->nextRowList = ptrRow->nextRowList;
            ptrRow->nextRowList->nextRowList = ptrRow;
            ptrRow->nextRowList->prevRowList = ptrRow->prevRowList;
            ptrRow->prevRowList = ptrRow->nextRowList;
            ptrRow->nextRowList = copy;
            if (copy!=0)
            {
                copy->prevRowList = ptrRow;
            }
            

        }
    }
    std::cout<<"exit "; 
}