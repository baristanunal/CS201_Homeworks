/*
    CABINET.H
    Created by Barış Tan Ünal on 3.11.2021.
    Author: Barış Tan Ünal
    ID: 22003617
*/


#ifndef LABORGANIZER_CABINET_H
#define LABORGANIZER_CABINET_H

#include "Chemical.h"

class Cabinet {

public:
    Cabinet( int id, int rowCount, int columnCount );
    Cabinet();
    Cabinet( const Cabinet& cab );
    ~Cabinet();

    int getCabinetId() const;
    void setCabinetId( int id );

    int getRowCount() const;
    void setRowCount( int r );

    int getColumnCount() const;
    void setColumnCount( int c );

    int getDim() const;
    void setDim( int d );

    int getEmptyCount() const;
    void setEmptyCount( int e );

    Chemical* findChemicalInCab( int id );
    int isInCabinet( int id );
    int isOccupied( string location );
    int canPlaced( string location, int type );
    int alternativePos( string location, int type );
    void placeChemToCab( int chemID, int chemType, string location );
    static char numToChar( int index );
    static int charToNum( char letter );

    void printChemicalsText();
    void displayContents() const;
    int removeChemFromCab( int id );



private:
    int cabinetId;
    int rowCount;
    int columnCount;
    int emptySlots;
    Chemical*** contents;
    int dimension;

};

#endif //LABORGANIZER_CABINET_H