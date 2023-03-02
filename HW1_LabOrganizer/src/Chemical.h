/*
    CHEMICAL.H
    Created by Barış Tan Ünal on 3.11.2021.
    Author: Barış Tan Ünal
    ID: 22003617
*/

/*
#ifndef LABORGANIZER_CHEMICAL_H
#define LABORGANIZER_CHEMICAL_H

#include <string>
using namespace std;

class Chemical {

public:

    Chemical();
    Chemical( int id, string type, string location );

    ~Chemical();

    int getChemId() const;
    void setChemId( int i );

    string getChemLocation() const;
    void setChemLocation( const string& l );

    string getChemType() const;
    void setChemType( const string& t );

private:
    string chemType;
    string location;
    int chemId;

};

#endif //LABORGANIZER_CHEMICAL_H
*/

#ifndef LABORGANIZER_CHEMICAL_H
#define LABORGANIZER_CHEMICAL_H

#include <string>
using namespace std;

class Chemical {

public:

    Chemical();
    Chemical( int id, int type, string location );

    ~Chemical();

    int getChemId() const;
    void setChemId( int i );

    string getChemLocation() const;
    void setChemLocation( const string& l );

    int getChemType() const;
    void setChemType( int t );

private:
    int chemType; // 0: retardant, 1: combustive.
    string location;
    int chemId;

};

#endif //LABORGANIZER_CHEMICAL_H
