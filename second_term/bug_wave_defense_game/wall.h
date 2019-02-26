#include "ant.h"
using namespace std;

#ifndef WALL_H
#define WALL_H
class wall : public ant{
  public:
    wall(int location);
    void action();

};
#endif
