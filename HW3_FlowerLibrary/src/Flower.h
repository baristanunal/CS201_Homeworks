//
// FLOWER.H
// Barış Tan Ünal
// 22003617
//

#ifndef HOMEWORK3_FLOWER_H
#define HOMEWORK3_FLOWER_H

#include <string>
using namespace std;

class Flower{

private:
    struct FeatureNode{
        string feature;
        FeatureNode* next;
    };
    int size;
    string flowerName;
    FeatureNode* head; //the features are stored in a sorted singly linear linked list
    // ...
    //you may define additional member functions and data members, if necessary

public:
    Flower();
    Flower(string flowerName);
    Flower(const Flower& aFlower);
    ~Flower();
    bool isEmpty() const;
    int getLength() const;
    void setSize( int newSize );
    string getFlowerName() const;
    void setFlowerName( string name );
    bool add(string feature);
    bool remove(string feature);
    string printFlower() const;
    bool hasFeature( string feature ) const;

};

#endif //HOMEWORK3_FLOWER_H
