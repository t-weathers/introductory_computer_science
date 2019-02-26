#include "ant.h"
using namespace std;

#ifndef SHORT_THROWER_H
#define SHORT_THROWER_H
class short_thrower : public ant{
  public:
    short_thrower(int location);
    void action();

};
#endif
