//
// FLOWERLIST.CPP
// Barış Tan Ünal
// 22003617
//

#include "FlowerList.h"
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// Constructors
FlowerList::FlowerList() {

    head = NULL;
    size = 0;
}

FlowerList::FlowerList(const FlowerList &aList) {

    // original list is empty
    if( (aList.head)->next == NULL ) {
        head->next = NULL;
    }
    else {
        head->next = new FlowerNode();
        (head->next)->flower = ((aList.head)->next)->flower;

        FlowerNode* newPtr = head->next;

        for( FlowerNode* origPtr = aList.head->next->next; origPtr != NULL;
              origPtr = origPtr->next ){
            newPtr->next = new FlowerNode;
            newPtr = newPtr->next;
            newPtr->flower = origPtr->flower;
        }
        newPtr->next = NULL;
    }

}

// FlowerList Destructor
FlowerList::~FlowerList() {

    //cout << "Calling FlowerList destructor..." << endl;

    FlowerNode* cur;

    while( getLength() > 0 ){
        cur = head;
        head = head->next;
        delete cur;
        size = size - 1;
    }

}


// Methods
bool FlowerList::isEmpty() const {
    return ( getLength() == 0 );
}

int FlowerList::getLength() const {
    return size;
}

bool FlowerList::retrieve(string flowerName, Flower& flower) const {

    if( getLength() == 0 ) {
        return false;
    }

    FlowerNode* cur;
    cur = head;

    for( int i = 0; i < getLength(); i++ ) {

        if( (cur->flower).getFlowerName() == flowerName ){
            flower = cur->flower;
            return true;
        }
        else {
            cur = cur->next;
        }
    }

    // flower not found
    // flower = NULL;
    return false;
}


bool FlowerList::add( string flowerName ) {

    // Transform feature string to all lower case.
    std::transform(flowerName.begin(), flowerName.end(), flowerName.begin(), ::tolower);

    // Create a new node to be inserted.
    FlowerNode* newNode;
    newNode = new FlowerNode();
    newNode->flower.setFlowerName( flowerName );
    newNode->next = NULL;

    FlowerNode* cur;

    if( getLength() == 0 ) {
        head = newNode;
        newNode = NULL;
        size++;
        return true;
    }

    if( std::string((head->flower).getFlowerName()) > flowerName ) {
        newNode->next = head;
        head = newNode;
        newNode = NULL;
        size++;
        return true;
    }

    cur = head;

    while( cur->next != NULL ) {

        if( std::string( (cur->flower).getFlowerName() ) == flowerName ) {
            // feature already exists.
            delete newNode;
            return false;
        }
        else if( std::string( (cur->next->flower).getFlowerName() ) > flowerName ) {

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
    cur->next = newNode;
    newNode->next = NULL;
    size++;
    newNode = NULL;
    return true;
}


bool FlowerList::remove(string flowerName) {

    std::transform(flowerName.begin(), flowerName.end(), flowerName.begin(), ::tolower);

    FlowerNode* cur;
    FlowerNode* prev;

    // empty list.
    if( getLength() == 0 ) {
        return false;
    }

    // list with one feature.
    if( getLength() == 1) {
        if( (head->flower).getFlowerName() == flowerName ) {
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

        if( (cur->flower).getFlowerName() == flowerName ){

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


Flower* FlowerList::getNodeByIndex(int flowerIndex) const {

    if( getLength() == 0 ) {
        return NULL;
    }

    FlowerNode* cur;
    cur = head;

    for( int i = 0; i < flowerIndex; i++ ) {
        if( cur != NULL ) {
            cur = cur->next;
        }
        else {
            return NULL;
        }
    }
    return &cur->flower;
}

void FlowerList::findFlowersWithFeature(string feature) const {

    //Flower* curFlower;
    FlowerNode* curPtr;
    curPtr = head;
    bool found = false;
    int i = 0;

    while( curPtr != NULL ) {
        if( (curPtr->flower).hasFeature( feature ) ) {
            cout << (curPtr->flower).getFlowerName();
            found = true;
            if( i < getLength() - 1 ) {
                cout << ", ";
            }
        }
        i++;
        curPtr = curPtr->next;
    }
    if( !found ){
        cout << "there is no such flower";
    }
    cout << endl;
    curPtr = NULL;

}

bool FlowerList::addFeatureInList(string flowerName, string feature) {

    std::transform(flowerName.begin(), flowerName.end(), flowerName.begin(), ::tolower);
    std::transform(feature.begin(), feature.end(), feature.begin(), ::tolower);

    FlowerNode* cur;

    // empty list.
    if( getLength() == 0 ) {
        cout << flowerName << " isn't found in library." << endl;
        return false;
    }

    // non empty list.
    cur = head;

    while( cur != NULL ) {

        if( (cur->flower).getFlowerName() == flowerName ){

            if( (cur->flower).add( feature ) ) {
                cout << feature << " is added into " << flowerName << endl;
                return true;
            }
            else {
                cout << feature << " already exists in " << flowerName << endl;
                return false;
            }
        }
        else {
            cur = cur->next;
        }
    }
    cout << flowerName << " is not found in library." << endl;
    return false;

}


Flower *FlowerList::findFlower( string flowerName) {

    Flower* flowerPtr;

    if( getLength() == 0 ) {
        return NULL;
    }

    FlowerNode* cur;
    cur = head;

    for( int i = 0; i < getLength(); i++ ) {

        if( (cur->flower).getFlowerName() == flowerName ){
            flowerPtr = &(cur->flower);
            return flowerPtr;
        }
        else {
            cur = cur->next;
        }
    }

    flowerPtr = NULL;
    return NULL;
}


bool FlowerList::removeFeatureInList( string flowerName, string feature) {

    FlowerNode* cur;

    // empty list.
    if( getLength() == 0 ) {
        cout << flowerName << " does not exist in the library." << endl;
        return false;
    }

    // non empty list.
    cur = head;

    while( cur != NULL ) {

        if( (cur->flower).getFlowerName() == flowerName ){

            if( (cur->flower).remove( feature ) ) {
                cout << feature << " is removed from " << flowerName << endl;
                return true;
            }
            else {
                cout << feature << " doesn't exist in " << flowerName << endl;
                return false;
            }
        }
        else {
            cur = cur->next;
        }
    }
    cout << feature << " doesn't exist in " << flowerName << endl;
    return false;

}

bool FlowerList::isPresent(string flowerName) const {

    if( getLength() == 0 ) {
        return false;
    }

    FlowerNode* cur;
    cur = head;

    for( int i = 0; i < getLength(); i++ ) {

        if( (cur->flower).getFlowerName() == flowerName ){
            return true;
        }
        else {
            cur = cur->next;
        }
    }

    // flower not found
    return false;
}

Flower* FlowerList::getNode(string flowerName) const {

    if( getLength() == 0 ) {
        return NULL;
    }

    FlowerNode* cur;
    cur = head;

    for( int i = 0; i < getLength(); i++ ) {

        if( (cur->flower).getFlowerName() == flowerName ){
            return &(cur->flower);
        }
        else {
            cur = cur->next;
        }
    }

    // flower not found
    return NULL;
}

