#include "ant.h"
using namespace std;

#ifndef BODYGUARD_H
#define BODYGUARD_H
class bodyguard : public ant{
  public:
    bodyguard(int location);
    void action();

};
#endif
