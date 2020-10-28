#ifndef BRACELET_23_H
#define BRACELET_23_H

#include "equipment.h"

class Bracelet_23 : public Equipment { // 天衍万物 Bracelet: 7
  public:
    Bracelet_23() {}
	void operator() (Character &model);
};

#endif // BRACELET_23_H
