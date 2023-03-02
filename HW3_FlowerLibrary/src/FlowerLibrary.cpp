//
// FLOWERLIBRARY.CPP
// Barış Tan Ünal
// 22003617
//

#include <iostream>
#include <algorithm>
#include "FlowerLibrary.h"
#include <string>

using namespace std;

// Constructor
FlowerLibrary::FlowerLibrary() {

    FlowerList flowers();
}

// FlowerLibrary Destructor
FlowerLibrary::~FlowerLibrary(){
    //cout << "Calling FlowerLibrary destructor..." << endl;
}


// Methods
void FlowerLibrary::addFlower(string name) {

    std::transform(name.begin(), name.end(), name.begin(), ::tolower);

    if ( flowers.add( name )) {
        cout << name << " has been added into the library" << endl;
    }
    else {
        cout << name << " cannot be added into the library because it already exists" << endl;
    }
}

void FlowerLibrary::removeFlower(string name) {

    std::transform(name.begin(), name.end(), name.begin(), ::tolower);

    if( flowers.remove( name ) ) {
        cout << name << " has been removed from the library" << endl;
    }
    else {
        cout << name << " cannot be removed because it's not in the library" << endl;
    }
}

void FlowerLibrary::listFlowers() const {

    if( flowers.isEmpty() ){
        cout << "Library is empty." << endl;
    }
    else {
        Flower* curFlower;
        for( int i = 0; i < flowers.getLength(); i++ ){
            curFlower = flowers.getNodeByIndex( i );
            curFlower->printFlower();
        }
        curFlower = NULL;
    }
}

void FlowerLibrary::listFeatures(string name) const {

    std::transform(name.begin(), name.end(), name.begin(), ::tolower);

    Flower* thisFlower;
    if ( flowers.isPresent( name ) ){
        thisFlower = flowers.getNode( name );
        thisFlower->printFlower();
        cout << endl;
        thisFlower = NULL;
    }
    else {
        cout << name << " is not found in the library" << endl;
    }

}

void FlowerLibrary::addFeature(string name, string feature) {

    std::transform(name.begin(), name.end(), name.begin(), ::tolower);
    std::transform(feature.begin(), feature.end(), feature.begin(), ::tolower);

    flowers.addFeatureInList( name, feature );

}

void FlowerLibrary::removeFeature(string name, string feature) {

    std::transform(name.begin(), name.end(), name.begin(), ::tolower);
    std::transform(feature.begin(), feature.end(), feature.begin(), ::tolower);

    flowers.removeFeatureInList( name, feature );

}

void FlowerLibrary::findFlowers(string feature) const {

    cout << feature << " flowers: ";
    flowers.findFlowersWithFeature( feature );

}
