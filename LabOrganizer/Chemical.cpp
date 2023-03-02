/*
    CHEMICAL.CPP
    Created by Barış Tan Ünal on 3.11.2021.
    Author: Barış Tan Ünal
    ID: 22003617
*/

#include "Chemical.h"

Chemical::Chemical() {

    chemId = -1;
    chemType = 0;
    location = "null";

}

Chemical::~Chemical(){

}

Chemical::Chemical( int id, int type, string loc ) {

    chemId = id;
    chemType = type;
    location = loc;

}

int Chemical::getChemId() const {
    return chemId;
}

void Chemical::setChemId( const int i ) {
    chemId = i;
}

string Chemical::getChemLocation() const {
    return location;
}

void Chemical::setChemLocation( const string& l ) {
    location = l;
}

int Chemical::getChemType() const {
    return chemType;
}

void Chemical::setChemType( const int t ) {
    chemType = t;
}


