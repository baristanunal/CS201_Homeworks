//
// FLOWER.CPP
// Barış Tan Ünal
// 22003617
//

#include <iostream>
#include <algorithm>
#include "Flower.h"

using namespace std;

// Constructors
Flower::Flower() {

    head = NULL;
    size = 0;
    flowerName = "";
}

Flower::Flower(string name) {

    std::transform(name.begin(), name.end(), name.begin(), ::tolower);
    head = NULL;
    size = 0;
    flowerName = name;
}

// Copy Constructor
Flower::Flower( const Flower& aFlower ) {

    if (aFlower.head == NULL)
        head = NULL;  // original list is empty
    else {
        // copy first node
        head = new FeatureNode;
        head->feature = aFlower.head->feature;
        // copy rest of list
        FeatureNode *newPtr = head;  // new list ptr

        for ( FeatureNode *origPtr = aFlower.head->next; origPtr != NULL;
              origPtr = origPtr->next){
            newPtr->next = new FeatureNode;
            newPtr = newPtr->next;
            newPtr->feature = origPtr->feature;
        }
        newPtr->next = NULL;
    }
}

// Flower Destructor
Flower::~Flower() {

    //cout << "Calling Flower destructor..." << endl;

    FeatureNode* cur;

    while( getLength() > 0 ){
        cur = head;
        head = head->next;
        delete cur;
        size = size - 1;
    }

}


// Methods

bool Flower::isEmpty() const {
    return (head == NULL);
}

int Flower::getLength() const {
    return size;
}

bool Flower::add( string feature ) {

    // Transform feature string to all lower case.
    std::transform(feature.begin(), feature.end(), feature.begin(), ::tolower);

    // Create a new node to be inserted.
    FeatureNode* newNode;
    newNode = new FeatureNode();
    newNode->feature = feature;
    newNode->next = NULL;

    FeatureNode* cur;

    if( getLength() == 0 ) {
        head = newNode;
        newNode = NULL;
        size++;
        return true;
    }

    if( std::string(head->feature) > feature ) {
        newNode->next = head;
        head = newNode;
        newNode = NULL;
        size++;
        return true;
    }

    cur = head;

    while( cur->next != NULL ) {

        if( std::string( cur->feature ) == feature ) {
            // feature already exists.
            delete newNode;
            return false;
        }
        else if( std::string( cur->next->feature ) > feature ) {

            newNode->next = cur->next;
            cur->next = newNode;
            size++;
            newNode = NULL;
            return true;
        }
        else {
            cur = cur->next;
        }
    }

    // for last place case.
    if( std::string( cur->feature ) == feature ) {
        delete newNode;
        return false;
    }
    else {
        cur->next = newNode;
        newNode->next = NULL;
        size++;
        newNode = NULL;
        return true;
    }
}

bool Flower::remove(string feature) {

    std::transform(feature.begin(), feature.end(), feature.begin(), ::tolower);

    FeatureNode* cur;
    FeatureNode* prev;

    // empty list.
    if( getLength() == 0 ) {
        return false;
    }

    // list with one feature.
    if( getLength() == 1) {
        if( head->feature == feature ) {
            delete head;
            head = NULL;
            size--;
            return true;
        }
        return false;
    }

    // list with multiple features.
    prev = NULL;
    cur = head;

    while( cur != NULL ) {

        if( cur->feature == feature ){

            // if item to remove is at index 0.
            if( prev == NULL ) {
                head = cur->next;
            }
            else {
                prev->next = cur->next;
            }
            cur->next = NULL;

            delete cur;
            cur = NULL;
            size--;
            return true;
        }
        else {
            prev = cur;
            cur = cur->next;
        }
    }
    // should not end up here anyways?
    return false;

}

string Flower::printFlower() const {

    cout << flowerName << ": ";

    if( isEmpty() ) {
        cout << "No feature" << endl;
    }
    else {

        FeatureNode* cur;
        cur = head;

        for( int i = 0; i < getLength(); i++ ) {

            cout << cur->feature;
            cur = cur->next;
            if( i != getLength() - 1 ){
                cout << ", ";
            }
        }
        cur = NULL;
    }

    return std::string();
}


string Flower::getFlowerName() const {
    return flowerName;
}

bool Flower::hasFeature(string feature) const {

    if( isEmpty() ) {
        return false;
    }
    else {

        FeatureNode* cur;
        cur = head;

        for( int i = 0; i < getLength(); i++ ) {

            if( cur->feature == feature ) {
                cur = NULL;
                return true;
            }
            else {
                cur = cur->next;
            }
        }
        cur = NULL;
        return false;
    }

}

void Flower::setFlowerName(string name) {
    flowerName = name;
}

void Flower::setSize(int newSize) {
    size = newSize;
}


