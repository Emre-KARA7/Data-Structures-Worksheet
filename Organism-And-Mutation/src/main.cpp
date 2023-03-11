
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include <stdlib.h>   
#include <time.h> 

#include "Cell.hpp"
#include "Tissue.hpp"
#include "Organ.hpp"
#include "System.hpp"
#include "Organism.hpp"


int main() {
    std::ifstream file("Veri.txt");
    std::string line;
    std::string word;
    Organism* currentOrganism = 0;
    System* currentSystem = 0;
    Organ* currentOrgan = 0;
    Tissue* currentTissue = 0;
    Cell* currentCell = 0;
    int numberOfLinesRead = 0, num = 0;
    // // // // // // // // // // // // // // // // // //

    if (file.is_open()) {
        Organism* organism = new Organism();
        currentOrganism = organism;

        while (std::getline(file, line)) {

            if (numberOfLinesRead % 2000 == 0) {
                System* system = new System();
                currentSystem = system;
                currentOrganism->add(currentSystem);
            }
            if (numberOfLinesRead % 20 == 0) {
                Organ* organ = new Organ();
                currentOrgan = organ;
                currentSystem->add(currentOrgan);
            }
            Tissue* tissue = new Tissue();
            currentTissue = tissue;
            std::istringstream iss(line);
            while (iss >> word) {
                num = stoi(word);
                Cell* cell = new Cell();
                currentCell = cell;
                currentCell->cellSet(num);
                currentTissue->addCell(currentCell);
            }
            currentTissue->sort();
            currentOrgan->add(currentTissue);
            numberOfLinesRead++;
        }
        file.close();
    }


    system("cls");
    std::cout<<"                                     ORGANISM\n";
    currentOrganism->print();
    std::cin.ignore();
    system("cls");
    currentOrganism->mutate();
     std::cout<<"                               (MUTATED)  ORGANISM\n";
    currentOrganism->print();

    delete currentOrganism;
}
