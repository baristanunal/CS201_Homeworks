//
// FLOWERLIST.H
// Barış Tan Ünal
// 22003617
//

#ifndef HOMEWORK3_FLOWERLIST_H
#define HOMEWORK3_FLOWERLIST_H

#include <string>
#include "Flower.h"

class FlowerList{

private:
    struct FlowerNode{
        Flower flower;
        FlowerNode* next;
    };
    int size;
    FlowerNode* head;
    // ...
    //you may define additional member functions and data members, if necessary

public:
    FlowerList();
    FlowerList(const FlowerList& aList);
    ~FlowerList();
    bool isEmpty() const;
    int getLength() const;
    bool retrieve(string flowerName, Flower& flower) const;
    bool isPresent( string flowerName ) const;
    Flower* getNode( string flowerName ) const;
    Flower* getNodeByIndex( int flowerIndex) const;
    bool add(string flowerName);
    bool addFeatureInList( string flowerName, string feature );
    bool removeFeatureInList( string flowerName, string feature );
    Flower* findFlower( string flowerName );
    bool remove(string flowerName);
    void findFlowersWithFeature( string feature ) const;

};

#endif //HOMEWORK3_FLOWERLIST_H
