#include "ant.h"
using namespace std;

#ifndef THROWER_H
#define THROWER_H
class thrower : public ant{
  public:
    thrower(int location);
    void action();

};
#endif
