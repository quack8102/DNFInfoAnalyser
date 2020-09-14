#ifndef NECK_23_H
#define NECK_23_H

#include "equipment.h"

class Neck_23 : public Equipment { // 霸域英豪护肩 Neck: 0
  public:
    Neck_23() {}
	void operator() (Character &model);
};

#endif // NECK_23_H
