#include "ant.h"
using namespace std;

#ifndef NINJA_H
#define NINJA_H
class ninja : public ant{
  public:
    ninja(int location);
    void action();

};
#endif
