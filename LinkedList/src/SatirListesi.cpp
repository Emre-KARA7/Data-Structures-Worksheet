#include "SatirListesi.hpp"
#include <iostream>
using namespace std;
SatirListesi::SatirListesi() {
	firstNode = 0;
	nextRowList = 0;
	average = 0;
	nodeCount = 0;
	prevRowList = 0;
}

void SatirListesi::calculateAverage(){
	if (firstNode !=0)
	{
		Dugum* temporaryNode = firstNode;
		float total= temporaryNode->data;
		while (temporaryNode->nextNode != 0)
		{
			temporaryNode = temporaryNode->nextNode;
			total += temporaryNode->data;
		}
		average = total / nodeCount;
	}
	else{
		average = 0;
	}
	
}
SatirListesi::~SatirListesi() {

}
void SatirListesi::deleteNode(int nodeIndex){
	Dugum* tempNode1 = firstNode;
	if (nodeIndex == 0)
	{
		if (nodeCount!=1)
		{
			firstNode  = tempNode1->nextNode;
		}
		else{
			firstNode=0;
		}
	}
	else{
		for (int i = 0; i < nodeIndex-1; i++)
		{
			tempNode1 = tempNode1->nextNode;
		}
		Dugum* tempNode2 = tempNode1;
		tempNode1 = tempNode1->nextNode;
		tempNode2->nextNode = tempNode1->nextNode;
	}
	delete tempNode1;
	nodeCount--;
}


