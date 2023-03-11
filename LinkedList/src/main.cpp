#include <fstream>
#include <iostream>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "YoneticiListesi.hpp"
#include "SatirListesi.hpp"
void Menu(int cardIndex, bool k, int randDelIndex);
YoneticiListesi* List = new YoneticiListesi();

int main() {
    std::ifstream file("veriler.txt");
    std::string line;
    std::string word;


    if (file.is_open()) {
        while (std::getline(file, line)) {
            SatirListesi* ptr = List->createRow();
            std::istringstream iss(line);
            while (iss >> word) {
                int num = stoi(word);
                List->addToRow(num);
            }
            List->sort(ptr);
        }
        file.close();
    }

    int randDelIndex;
    bool k = false;
    bool exit=false;
    char c;
    int menuIndex=0;
    do
    {
        Menu(menuIndex,k,randDelIndex);
        std::cin>>c;
        if (c == 'z')
        {
             if (!menuIndex-1<0)
            {
                menuIndex--;
            }
            k=false;
        }
        else if (c == 'c')
        {
            if (menuIndex+1<List->rowListCount)
            {
                menuIndex++;
            }
            k=false;
        }
        else if(c=='a'){
            if (menuIndex - 8 >= 0)
            {
                menuIndex-=8;
            }
            k=false;
        }
        else if(c=='d'){
            if (menuIndex+8<List->rowListCount)
            {
                menuIndex+=8;
            }
            k=false;
        }
        else if (c == 'p')
        {
          List->delRow(menuIndex);
          k=false;
        }
        else if (c == 'k' && k)
        {
          List->delRandNode(menuIndex, randDelIndex);
          k=false;
        }
        else if(c=='k'){
            k=true;
            randDelIndex = List->delRandIndex(menuIndex);
        }
        else if (c == '.')
        {
            exit=true;
        }
        while (menuIndex >= List->rowListCount)
        {
            menuIndex--;
        }
        if (!List->rowListCount > 0)
        {
            system("cls");
            exit=true;
        }
        
    } while (!exit);
 
    return 0;
}

void Menu(int cardIndex, bool k, int randDelIndex){
    int page = (cardIndex/8);
    int cardCount = 8;
    if (List->rowListCount - (page*8)>=8)
    {
        cardCount=8;
    }
    else{
        cardCount = (List->rowListCount - (page*8))%8;
    }
    
    int digit = 8;
    int width= 12;
    system("cls");
    std::cout<<" ilk"<<std::setw(91)<<"-->"<<std::endl;
    for (int i = 0; i < cardCount; i++)
    {
        std::cout<<" __________ ";
    }
    std::cout<<std::endl;
    for (int i = 0; i < cardCount; i++)
    {
        std::cout<<" |"<<std::setw(digit)<<List->cast(i,"this")<<"| ";
    }
    std::cout<<std::endl;
    for (int i = 0; i < cardCount; i++)
    {
        std::cout<<" __________ ";
    }
    std::cout<<std::endl;
    for (int i = 0; i < cardCount; i++)
    {
        std::cout<<" |"<<std::setw(digit)<<List->cast(i+(8*page),"prev")<<"| ";
    }
    std::cout<<std::endl;
    for (int i = 0; i < cardCount; i++)
    {
        std::cout<<" __________ ";
    }
    std::cout<<std::endl;
    for (int i = 0; i < cardCount; i++)
    {
        std::cout<<" |"<<std::setw(digit)<<List->cast(i+(8*page),"average")<<"| ";
    }
    std::cout<<std::endl;
    for (int i = 0; i < cardCount; i++)
    {
        std::cout<<" __________ ";
    }
    std::cout<<std::endl;
    for (int i = 0; i < cardCount; i++)
    {
        std::cout<<" |"<<std::setw(digit)<<List->cast(i+(8*page),"next")<<"| ";
    }
    std::cout<<std::endl<<std::endl;
    ///////////////////////////////////////////////////
    std::string del;




    for (int i = 0; i < std::stoi(List->cast(cardIndex,"nodeCount")); i++)
    {
        if (k && randDelIndex==i)//buray k ifade koy
        {
            del="<--";
        }
        else{
            del="";
        }
        std::cout<<std::setw(width*(cardIndex%8)+11)<<"^^^^^^^^^^"<<std::endl
                <<std::setw(width*(cardIndex%8)+11)<<"^^^^^^^^^^"<<std::endl
                <<std::setw(width*(cardIndex%8)+11)<<"__________"<<std::endl
                <<std::setw(width*(cardIndex%8)+2)<<"|"<<std::setw(digit)<<List->cast(cardIndex, i, "this")<<"|"<< del<<std::endl
                <<std::setw(width*(cardIndex%8)+11)<<"__________"<<std::endl
                <<std::setw(width*(cardIndex%8)+2)<<" |"<<std::setw(digit)<<List->cast(cardIndex, i, "data")<<"|"<<std::endl
                <<std::setw(width*(cardIndex%8)+11)<<"__________"<<std::endl
                <<std::setw(width*(cardIndex%8)+2)<<" |"<<std::setw(digit)<<List->cast(cardIndex, i, "next")<<"|"<<std::endl<<std::endl;
    }

}