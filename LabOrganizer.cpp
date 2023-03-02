/*
    LAB_ORGANIZER.CPP
    Created by Barış Tan Ünal on 2.11.2021.
    Author: Barış Tan Ünal
    ID: 22003617
*/


#include <iostream>
#include "LabOrganizer.h"
#include "Chemical.h"
#include "Cabinet.h"

using namespace std;

LabOrganizer::LabOrganizer() {
    size = 0;
    //cabinets = new Cabinet[1];
    // do not use new Cabinet[0] in constructor!
    // add an if clause to addCabinet: if the size is 0, call new Cabinet[1].
}

LabOrganizer::~LabOrganizer() {

    if( size != 0 ) {
        for( int i = 0; i < size; i++) {
            delete cabinets[ i ];
        }
        delete[] cabinets;
    }
    else{
        delete cabinets[ 0 ];
        delete[] cabinets;
    }

}


void LabOrganizer::addCabinet( int id, int rows, int columns ) {

    if( rows > 9 || columns > 9 ) {
        cout << "Cannot add cabinet: dimensions are out of bounds." << endl;
        return;
    }

    for( int i = 0; i < size; i++ ) {
        if( cabinets[ i ]->getCabinetId() == id ) {
            cout << "Cannot add cabinet: ID " << id << " already in the system." << endl;
            return;
        }
    }

    if( size == 0 ){
        cabinets = new Cabinet*[ 1 ];
    }

    else {
        // copying to a new array
        Cabinet** newCabPtr;
        newCabPtr = new Cabinet*[ size + 1 ];
        for ( int i = 0; i < size; i++ ) {

            newCabPtr[ i ] = cabinets[ i ];
            cabinets[ i ] = NULL;
        }

        delete[] cabinets;
        cabinets = newCabPtr;
        newCabPtr = NULL;

    }

    cabinets[ size ] = new Cabinet( id, rows, columns );

    size++;

    cout << "Added a cabinet: ID " << id << " and dimensions " << rows << " to " << columns << "." << endl;
}


void LabOrganizer::removeCabinet( int id ) {

    for( int i = 0; i < size; i++ ) {
        if( cabinets[ i ]->getCabinetId() == id ) {

            delete cabinets[ i ];
            cabinets[ i ] = NULL;

            for( int j = i; j < size - 1; j++ ) {

                cabinets[ j ] = cabinets[ j + 1 ];
                cabinets[ j + 1 ] = NULL;
            }
            size--;
            cout  << "Cabinet " << id << " has been removed." << endl;
            return;
        }
    }
    cout << "Cabinet " << id << " does not exist in the system." << endl;
}


void LabOrganizer::listCabinets() {

    for( int i = 0; i < size; i++ ) {
        cout << "ID: " << cabinets[ i ]->getCabinetId() << ", Dim: " << cabinets[ i ]->getRowCount()
             << "x" << cabinets[ i ]->getColumnCount() << ", Number of empty slots: "
             << cabinets[ i ]->getEmptyCount() << endl;
    }
    if( size == 0 ) {
        cout << "No cabinets found." << endl;
    }
}


void LabOrganizer::cabinetContents( int id ) {

    cout << endl;
    for( int i = 0; i < size; i++ ) {
        if( cabinets[ i ]->getCabinetId() == id ){
            cout << "ID: " << id << ", " << cabinets[ i ]->getRowCount() << "x" << cabinets[ i ]->getColumnCount()
                 << ", empty: " << cabinets[ i ]->getEmptyCount() << ". Chemicals: ";
            cabinets[ i ]->printChemicalsText();
            cabinets[ i ]->displayContents();
            //cout << "displayed successfully" << endl;
            return;
        }
    }
}

void LabOrganizer::placeChemical( const int cabinetId, const string location, const string chemType, const int chemID) {

    bool proposed = false;
    int chemTypeInt;
    int cabinetIndex = -1;

    if( chemType == "combustive"){
        chemTypeInt = 1;
    }
    else if( chemType == "retardant" ){
        chemTypeInt = 0;
    }
    else{
        cout << endl << "Invalid chemical type!" << endl;
        return;
    }

    for( int i = 0; i < size; i++ ){
        if( cabinets[ i ]->getCabinetId() == cabinetId ) {
            cabinetIndex = i;
        }
    }

    if( cabinetIndex == -1 ){
        cout << "Cabinet " << cabinetId << " does not exist in the system." << endl;
        return;
    }

    for( int i = 0; i < size; i++ ) {
        if( cabinets[ i ]->isInCabinet( chemID ) ) {
            cout << "Chemical ID with " << chemID << " already exists in the system." << endl;
            return;
        }
    }


    if( cabinets[ cabinetIndex ]->isOccupied( location ) == 0 ) {

        //cout << "  checking if occupied" << endl;
        if( cabinets[ cabinetIndex ]->canPlaced(location, chemTypeInt) ) {

            cabinets[ cabinetIndex ]->placeChemToCab( chemID, chemTypeInt, location );

            cout << chemType << " chemical with ID " << chemID << " has been placed at location " << location
            << " in cabinet " << cabinetId << endl;

            return;
        }
        cout << "Location " << location << " in cabinet " << cabinetId
             << " is not suitable for combustive chemical. Nearest possible locations for this chemical: " << endl;
             //<< cabinets[cabinetIndex]->alternativePos(location, chemTypeInt) << endl;

        return;
    }

    cout << "Location " << location << " in cabinet " << cabinetId
         << " is already occupied. Nearest possible locations for this chemical: " << endl;
    //<< cabinets[cabinetIndex]->alternativePos(location, chemTypeInt) << endl;

}


void LabOrganizer::findChemical( int id ) {

    for( int i = 0; i < size; i++ ){

        if( cabinets[ i ]->findChemicalInCab( id ) != NULL ) {
            cout << "Chemical " << cabinets[ i ]->findChemicalInCab( id )->getChemId()
                 << " is at location " << cabinets[ i ]->findChemicalInCab( id )->getChemLocation()
                 << " in cabinet " << cabinets[ i ]->getCabinetId() << endl;
            return;
        }

    }
    cout << "Chemical " << id << " is not in the system." << endl;
}


void LabOrganizer::removeChemical( int id ) {

    for( int i = 0; i < size; i++ ){

        if( cabinets[ i ]->isInCabinet( id ) == 1 ) {

            cabinets[ i ]->removeChemFromCab( id );

            cout << "Chemical " << id << " is removed from cabinet " << cabinets[ i ]->getCabinetId() << endl;
            return;
        }
    }
    cout << "Chemical " << id << " is not in the system." << endl;
}


int LabOrganizer::getSize() const {
    return size;
}



