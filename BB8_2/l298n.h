#ifndef L298N_H
#define L298N_H

#include "Arduino.h"
class L298N{

  public:
    L298N(int en, int p1, int p2);
    void  fwd(int s);
    void  rev(int s);
    void  stop();

  private:
    int P1, P2, E;    
};
#endif
