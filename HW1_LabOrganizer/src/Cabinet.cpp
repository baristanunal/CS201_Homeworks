/*
    CABINET.CPP
    Created by Barış Tan Ünal on 3.11.2021.
    Author: Barış Tan Ünal
    ID: 22003617
*/

#include <iostream>
#include <typeinfo>
#include "Cabinet.h"
#include "Chemical.h"

using namespace std;


Cabinet::Cabinet() {

}

Cabinet::Cabinet(const Cabinet &cab) {

    cabinetId = cab.getCabinetId();
    rowCount = cab.getRowCount();
    columnCount = cab.getColumnCount();
    emptySlots = cab.getEmptyCount();
    dimension = cab.getDim();

    for( int i = 0; i < rowCount; i++ ) {
        for( int j = 0; j < columnCount; j++ ) {
            contents[ i ][ j ]->setChemId( cab.contents[ i ][ j ]->getChemId() );
            contents[ i ][ j ]->setChemType( cab.contents[ i ][ j ]->getChemId() );
            contents[ i ][ j ]->setChemLocation( cab.contents[ i ][ j ]->getChemLocation() );
        }
    }
}



Cabinet::Cabinet( int id, int row, int column ) {
    cabinetId = id;
    rowCount = row;
    columnCount = column;
    dimension = row * column;
    emptySlots = row * column;

    contents = new Chemical**[ row ];
    for ( int i = 0; i < row; i++ ){
        contents[ i ] = new Chemical*[ column ];
    }

    for( int i = 0; i < row; i++) {
        for( int j = 0; j < column; j++) {
            contents[ i ][ j ] = NULL;
        }
    }
}

Cabinet::~Cabinet() {
    for ( int i = 0; i < rowCount; i++ ) {

        for ( int j = 0 ; j < columnCount; j++ ) {

            //cout << "deleting contents[ " << i << " ][ " << j << " ]..." << endl;
            delete contents[ i ][ j ];
        }
        delete[] contents[ i ];
    }
    delete[] contents;
}

/*
{
    for ( int i = 0; i < rowCount; i++ ) {
        cout << "column count : " << columnCount << endl;
        cout << "rowCount: " << rowCount << endl;
        for ( int j = 0 ; j < columnCount; j++ ) {
            cout << "check 2.0" << endl;
            if( contents[ i ][ j ] != NULL ) {
                delete contents[ i ][ j ];
            }
            cout << "check 2.1" << endl;
        }
        cout << "check 2.2 of " << i << endl;
        cout << contents[ i ] << endl;
        delete[] contents[ i ];
        cout << "check 2.3" << endl;
    }
    delete[] contents;
    cout << "check 2.4" << endl;
}
 */


int Cabinet::getCabinetId() const {
    return cabinetId;
}

void Cabinet::setCabinetId( const int id ) {
    cabinetId = id;
}

int Cabinet::getRowCount() const {
    return rowCount;
}

void Cabinet::setRowCount( const int r ) {
    rowCount = r;
}

int Cabinet::getColumnCount() const {
    return columnCount;
}

void Cabinet::setColumnCount( const int c ) {
    columnCount = c;
}

int Cabinet::getDim() const {
    return dimension;
}

void Cabinet::setDim( int d ) {
    dimension = d;
}

int Cabinet::getEmptyCount() const {
    return emptySlots;
}

void Cabinet::setEmptyCount( int e ) {
    emptySlots = e;
}


Chemical* Cabinet::findChemicalInCab( int id ) {

    for( int i = 0; i < rowCount; i++ ) {

        for( int j = 0; j < columnCount; j++ ) {

            if( contents[ i ][ j ] != NULL ) {

                if (contents[ i ][ j ]->getChemId() == id) {
                    return contents[ i ][ j ];
                }
            }

        }
    }
    return NULL;
}



int Cabinet::removeChemFromCab( int id ) {
    for( int i = 0; i < rowCount; i++ ) {
        for( int j = 0; j < columnCount; j++ ) {

            if( contents[ i ][ j ] != NULL ) {
                if (contents[i][j]->getChemId() == id) {

                    delete contents[i][j];
                    contents[i][j] = NULL;
                    return 1;
                }
            }
        }
    }
    return 0;
}


int Cabinet::isInCabinet( int id ) {
    for( int i = 0; i < rowCount; i++ ) {
        for( int j = 0; j < columnCount; j++ ) {

            if (contents[ i ][ j ] != NULL) {
                if (contents[ i ][ j ]->getChemId() == id) {
                    return 1;
                }
            }
        }
    }
    return 0;
}


void Cabinet::displayContents() const {

    cout <<"  ";
    for( int t = 0; t < this->getColumnCount(); t++ ) {

        cout << " " << t + 1;
    }
    cout << endl;

    for( int j = 0; j < this->getRowCount(); j++ ) {

        if( j == 0 ) {
            cout << " A";
        }
        else if( j == 1 ) {
            cout << " B";
        }
        else if( j == 2 ) {
            cout << " C";
        }
        else if( j == 3 ) {
            cout << " D";
        }
        else if( j == 4 ) {
            cout << " E";
        }
        else if( j == 5 ) {
            cout << " F";
        }
        else if( j == 6 ) {
            cout << " G";
        }
        else if( j == 7 ) {
            cout << " H";
        }
        else if( j == 8 ) {
            cout << " I";
        }


        for( int k = 0; k < this->getColumnCount(); k++ ) {

            if( contents[ j ][ k ] == NULL ) {
                cout << " +";
            }
            else if( contents[ j ][ k ]->getChemType() == 0 ){
                cout << " r";
            }
            else if( contents[ j ][ k ]->getChemType() == 1 ) {
                cout << " c";
            }
        }
        cout << endl;
    }

}

void Cabinet::printChemicalsText() {

    for( int i = 0; i < rowCount; i++ ){
        for( int j = 0; j < columnCount; j++ ) {

            if( contents[ i ][ j ] != NULL ) {
                if( i == 0 ) {
                    cout << "A";
                }
                else if( i == 1 ) {
                    cout << "B";
                }
                else if( i == 2 ) {
                    cout << "C";
                }
                else if( i == 3 ) {
                    cout << "D";
                }
                else if( i == 4 ) {
                    cout << "E";
                }
                else if( i == 5 ) {
                    cout << "F";
                }
                else if( i == 6 ) {
                    cout << "G";
                }
                else if( i == 7 ) {
                    cout << "H";
                }
                else if( i == 8 ) {
                    cout << "I";
                }

                cout << j + 1 << ": " << contents[ i ][ j ]->getChemId() << ", ";
            }
        }
    }
    cout << endl;
}

int Cabinet::isOccupied( string location ) {

    char column = location[ 1 ];
    int columnNo = column - 49;

    char row = location[ 0 ];
    int rowNo;

    if( row == 'A' ) {
        rowNo = 0;
    }
    if( row == 'B' ) {
        rowNo = 1;
    }
    if( row == 'C' ) {
        rowNo = 2;
    }
    if( row == 'D' ) {
        rowNo = 3;
    }
    if( row == 'E' ) {
        rowNo = 4;
    }
    if( row == 'F' ) {
        rowNo = 5;
    }
    if( row == 'G' ) {
        rowNo = 6;
    }
    if( row == 'H' ) {
        rowNo = 7;
    }
    if( row == 'I' ) {
        rowNo = 8;
    }

    if( contents[ rowNo ][ columnNo ] != NULL ) {
        return 1;
    }
    else {
        return 0;
    }
}



int Cabinet::canPlaced( string location, int type ) { // rows & columns [1 , 8]

    Chemical anyChem;

    char columnChar = location[ 1 ];
    int column = columnChar - 49;
    char rowChar = location[ 0 ];
    int row;

    if( rowChar == 'A' ) {
        row = 0;
    }
    if( rowChar == 'B' ) {
        row = 1;
    }
    if( rowChar == 'C' ) {
        row = 2;
    }
    if( rowChar == 'D' ) {
        row = 3;
    }
    if( rowChar == 'E' ) {
        row = 4;
    }
    if( rowChar == 'F' ) {
        row = 5;
    }
    if( rowChar == 'G' ) {
        row = 6;
    }
    if( rowChar == 'H' ) {
        row = 7;
    }
    if( rowChar == 'I' ) {
        row = 8;
    }

    if( type == 0 ) {

        return 1;
    }

    else {

        // 1st case: left top corner.
        if (row == 0 && column == 0) {
            for ( int i = row; i <= row + 1; i++ ) {
                for ( int j = column; j <= column + 1; j++ ) {
                    if ( !( i == row && j == column ) && contents[ i ][ j ] != NULL ) {
                        if( contents[ i ][ j ]->getChemType() == 1 ){
                            return 0;
                        }
                    }
                }
            }
        }

        // 2nd case: right top corner.
        else if (row == 0 && column == columnCount - 1 ) {
            for ( int i = row; i <= row + 1; i++ ) {
                for ( int j = column - 1; j <= column; j++ ) {
                    if ( !( i == row && j == column ) && contents[ i ][ j ] != NULL )  {
                        if( contents[ i ][ j ]->getChemType() == 1 ){
                            return 0;
                        }
                    }
                }
            }
        }


        // 3rd case: left bottom corner.
        else if (row == rowCount - 1 && column == 0 ) {
            for ( int i = row - 1; i <= row; i++ ) {
                for ( int j = column; j <= column + 1; j++ ) {
                    if ( !( i == row && j == column ) && contents[ i ][ j ] != NULL ) {
                        if( contents[ i ][ j ]->getChemType() == 1 ){
                            return 0;
                        }
                    }
                }
            }
        }

        // 4th case: right bottom corner.
        else if (row == rowCount - 1 && column == columnCount - 1 ) {
            for ( int i = row - 1; i <= row; i++ ) {
                for ( int j = column - 1; j <= column; j++ ) {
                    if ( !( i == row && j == column ) && contents[ i ][ j ] != NULL ) {
                        if( contents[ i ][ j ]->getChemType() == 1 ){
                            return 0;
                        }
                    }
                }
            }
        }

        // 5th case: left edge.
        else if ( 0 < row < rowCount - 1 && column == 0 ) {

            for ( int i = row - 1; i <= row + 1; i++ ) {
                for ( int j = column; j <= column + 1; j++ ) {
                    if ( !( i == row && j == column ) && contents[ i ][ j ] != NULL ) {
                        if( contents[ i ][ j ]->getChemType() == 1 ){
                            return 0;
                        }
                    }
                }
            }
        }

        // 6th case: right edge.
        else if ( 0 < row < rowCount - 1 && column == columnCount - 1 ) {
            for ( int i = row - 1; i <= row + 1; i++ ) {
                for ( int j = column - 1; j <= column; j++ ) {
                    if ( !( i == row && j == column ) && contents[ i ][ j ] != NULL ) {
                        if( contents[ i ][ j ]->getChemType() == 1 ){
                            return 0;
                        }
                    }
                }
            }
        }

        // 7th case: top edge.
        else if ( row == 0 && 0 < column < columnCount - 1 ) {
            for ( int i = row; i <= row + 1; i++ ) {
                for ( int j = column - 1; j <= column + 1; j++ ) {
                    if ( !( i == row && j == column ) && contents[ i ][ j ] != NULL ) {
                        if( contents[ i ][ j ]->getChemType() == 1 ){
                            return 0;
                        }
                    }
                }
            }
        }

        // 8th case: bottom edge.
        else if (row == rowCount - 1 && 0 < column < columnCount - 1) {
            for ( int i = row - 1; i <= row; i++ ) {
                for ( int j = column - 1; j <= column + 1; j++ ) {
                    if ( !( i == row && j == column ) && contents[ i ][ j ] != NULL ) {
                        if( contents[ i ][ j ]->getChemType() == 1 ){
                            return 0;
                        }
                    }
                }
            }
        }

        else {

            //cout << "middle case" << endl;

            for (int i = row - 1; i <= row + 1; i++) {
                for (int j = column - 1; j <= column + 1; j++) {
                    if (!(i == row && j == column ) && contents[ i ][ j ] != NULL ) {
                        if (contents[i][j]->getChemType() == 1) {
                            return 0;
                        }
                    }
                }
            }
        }

        //cout << "  chem can be placed to cabinet: " << cabinetId << ", location: " << location << endl;

        return 1;

        //cout << numToChar( i - 1 ) << j << ", ";
    }
}


void Cabinet::placeChemToCab(int chemID, int chemType, string location) {

    char columnChar = location[ 1 ];
    int column = columnChar - 49;
    char rowChar = location[ 0 ];
    int row;

    if( rowChar == 'A' ) {
        row = 0;
    }
    if( rowChar == 'B' ) {
        row = 1;
    }
    if( rowChar == 'C' ) {
        row = 2;
    }
    if( rowChar == 'D' ) {
        row = 3;
    }
    if( rowChar == 'E' ) {
        row = 4;
    }
    if( rowChar == 'F' ) {
        row = 5;
    }
    if( rowChar == 'G' ) {
        row = 6;
    }
    if( rowChar == 'H' ) {
        row = 7;
    }
    if( rowChar == 'I' ) {
        row = 8;
    }

    contents[ row ][ column ] = new Chemical( chemID, chemType, location );
    emptySlots--;

}


int Cabinet::alternativePos( string location, int type ) {

    Chemical currentChem;
    Chemical anyChem;

    char columnChar = location[ 1 ];
    int column = columnChar - 49;
    char rowChar = location[ 0 ];
    int row;

    if( rowChar == 'A' ) {
        row = 0;
    }
    if( rowChar == 'B' ) {
        row = 1;
    }
    if( rowChar == 'C' ) {
        row = 2;
    }
    if( rowChar == 'D' ) {
        row = 3;
    }
    if( rowChar == 'E' ) {
        row = 4;
    }
    if( rowChar == 'F' ) {
        row = 5;
    }
    if( rowChar == 'G' ) {
        row = 6;
    }
    if( rowChar == 'H' ) {
        row = 7;
    }
    if( rowChar == 'I' ) {
        row = 8;
    }

    if( type == 0 ) {
        return 1;
    }

    else {

        bool canPlaced = true;

        // 1st case: left top corner.
        if (row == 0 && column == 0) {
            for ( int i = row; i <= row + 1; i++ ) {
                for ( int j = column; j <= column + 1; j++ ) {
                    if ( !( i == row && j == column ) && contents[ i ][ j ] != NULL ) {
                        if( contents[ i ][ j ]->getChemType() == 1 ){
                            canPlaced = false;
                        }
                    }
                }
            }
        }

            // 2nd case: right top corner.
        else if (row == 0 && column == columnCount - 1 ) {
            for ( int i = row; i <= row + 1; i++ ) {
                for ( int j = column - 1; j <= column; j++ ) {
                    if ( !( i == row && j == column ) && contents[ i ][ j ] != NULL )  {
                        if( contents[ i ][ j ]->getChemType() == 1 ){
                            canPlaced = false;
                        }
                    }
                }
            }
        }


            // 3rd case: left bottom corner.
        else if (row == rowCount - 1 && column == 0 ) {
            for ( int i = row - 1; i <= row; i++ ) {
                for ( int j = column; j <= column + 1; j++ ) {
                    if ( !( i == row && j == column ) && contents[ i ][ j ] != NULL ) {
                        if( contents[ i ][ j ]->getChemType() == 1 ){
                            canPlaced = false;
                        }
                    }
                }
            }
        }

            // 4th case: right bottom corner.
        else if (row == rowCount - 1 && column == columnCount - 1 ) {
            for ( int i = row - 1; i <= row; i++ ) {
                for ( int j = column - 1; j <= column; j++ ) {
                    if ( !( i == row && j == column ) && contents[ i ][ j ] != NULL ) {
                        if( contents[ i ][ j ]->getChemType() == 1 ){
                            canPlaced = false;
                        }
                    }
                }
            }
        }

            // 5th case: left edge.
        else if ( 0 < row < rowCount - 1 && column == 0 ) {

            for ( int i = row - 1; i <= row + 1; i++ ) {
                for ( int j = column; j <= column + 1; j++ ) {
                    if ( !( i == row && j == column ) && contents[ i ][ j ] != NULL ) {
                        if( contents[ i ][ j ]->getChemType() == 1 ){
                            canPlaced = false;
                        }
                    }
                }
            }
        }

            // 6th case: right edge.
        else if ( 0 < row < rowCount - 1 && column == columnCount - 1 ) {
            for ( int i = row - 1; i <= row + 1; i++ ) {
                for ( int j = column - 1; j <= column; j++ ) {
                    if ( !( i == row && j == column ) && contents[ i ][ j ] != NULL ) {
                        if( contents[ i ][ j ]->getChemType() == 1 ){
                            canPlaced = false;
                        }
                    }
                }
            }
        }

            // 7th case: top edge.
        else if ( row == 0 && 0 < column < columnCount - 1 ) {
            for ( int i = row; i <= row + 1; i++ ) {
                for ( int j = column - 1; j <= column + 1; j++ ) {
                    if ( !( i == row && j == column ) && contents[ i ][ j ] != NULL ) {
                        if( contents[ i ][ j ]->getChemType() == 1 ){
                            canPlaced = false;
                        }
                    }
                }
            }
        }

            // 8th case: bottom edge.
        else if (row == rowCount - 1 && 0 < column < columnCount - 1) {
            for ( int i = row - 1; i <= row; i++ ) {
                for ( int j = column - 1; j <= column + 1; j++ ) {
                    if ( !( i == row && j == column ) && contents[ i ][ j ] != NULL ) {
                        if( contents[ i ][ j ]->getChemType() == 1 ){
                            canPlaced = false;
                        }
                    }
                }
            }
        }

        else {

            for (int i = row - 1; i <= row + 1; i++) {
                for (int j = column - 1; j <= column + 1; j++) {
                    if (!(i == row && j == column ) && contents[ i ][ j ] != NULL ) {
                        if (contents[i][j]->getChemType() == 1) {
                            canPlaced = false;
                        }
                    }
                }
            }
        }
        if( canPlaced ){
            cout << numToChar( row ) << column << ", ";
        }
    }
}


char Cabinet::numToChar( int index ) {

    char letter;

    if( index == 0 ) {
        letter = 'A';
    }
    else if( index == 1 ) {
        letter = 'B';
    }
    else if( index == 2 ) {
        letter = 'C';
    }
    else if( index == 3 ) {
        letter = 'D';
    }
    else if( index == 4 ) {
        letter = 'E';
    }
    else if( index == 5 ) {
        letter = 'F';
    }
    else if( index == 6 ) {
        letter = 'G';
    }
    else if( index == 7 ) {
        letter = 'H';
    }
    else if( index == 8 ) {
        letter = 'I';
    }

    return letter;
}



