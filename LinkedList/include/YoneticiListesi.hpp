#ifndef YoneticiListesi_hpp
#define YoneticiListesi_hpp
#include "SatirListesi.hpp"
#include <string>
class YoneticiListesi {
    public:
        YoneticiListesi();
        ~YoneticiListesi();
        int rowListCount;
        SatirListesi *firstRowList;
        void addToRow(int val);
        void sort(SatirListesi* ptrRow);
        SatirListesi* createRow();
        void delRandNode(int RowIndex, int delRandIndex);
        int delRandIndex(int RowIndex);
        void delRow(int RowIndex);
        std::string cast(int row, std::string type);
        std::string cast(int row, int index, std::string type);
};
#endif 