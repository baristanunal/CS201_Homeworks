/*
    LAB_ORGANIZER.H
    Created by Barış Tan Ünal on 2.11.2021.
    Author: Barış Tan Ünal
    ID: 22003617
*/


#ifndef LABORGANIZER_LABORGANIZER_H
#define LABORGANIZER_LABORGANIZER_H

#include <string>
#include "Chemical.h"
#include "Cabinet.h"
using namespace std;

class LabOrganizer{

public:
    LabOrganizer();
    ~LabOrganizer();

    void addCabinet(int id, int rows, int columns);
    void removeCabinet(int id);
    void listCabinets();
    void cabinetContents(int id);
    void placeChemical(int cabinetId, string location, string chemType, int chemID);
    void findChemical(int id);
    void removeChemical(int id);
    int getSize() const;


private:
    Cabinet** cabinets;
    int size;
};

#endif //LABORGANIZER_LABORGANIZER_H
