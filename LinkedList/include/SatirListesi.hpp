#ifndef SatirListesi_hpp
#define SatirListesi_hpp
#include "Dugum.hpp"
class SatirListesi {
	public:
		SatirListesi();
		~SatirListesi();
		SatirListesi* prevRowList;
		SatirListesi* nextRowList;
		Dugum* firstNode;
		float average;
		int nodeCount;
		void deleteNode(int nodeIndex);
		void calculateAverage();
		void printRowList();
};
#endif 
