#ifndef FOOLIB_H
#define FOOLIB_H 1

#include <cstdio>

namespace foolib {

class Animal {
protected:
    int _numLegs;

public:
    Animal() {}
    virtual ~Animal() {}

    int getNumLegs() {
        return _numLegs;
    }

    virtual void operation() {
        printf("Animal operation\n");
    }
};

class Dog : public Animal {
public:
    Dog() {
        _numLegs = 4;
    }

    virtual ~Dog() {}

    virtual void operation() {
        printf("Dog operation numLegs: %d\n", getNumLegs());
    }
};

}

#endif
