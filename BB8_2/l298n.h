#ifndef L298N_H
#define L298N_H

#include "Arduino.h"
class L298N{

  public:
    L298N(int en1, int p1, int p2, int en2, int p3, int p4);
    void  fwd(int s);
    void  rev(int s);
    void  left(int s);
    void  right(int s);
    void  stop();

  private:
    int P1, P2, E1;
    int P3, P4, E2;
    
};
#endif
