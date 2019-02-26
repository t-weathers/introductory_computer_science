#include "ant.h"
#include "space.h"
using namespace std;

#ifndef HARVESTER_H
#define HARVESTER_H
class harvester : public ant{
  public:
    harvester(int index);
    void action();

};
#endif
