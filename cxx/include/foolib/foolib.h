#ifndef FOOLIB_H
#define FOOLIB_H 1

namespace foolib {

class Animal {
public:
    int numLegs;
};

class Dog : public Animal {
public:
    Dog() {
        numLegs = 4;
    }
};

}

#endif

