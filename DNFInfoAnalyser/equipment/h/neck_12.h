#ifndef NECK_12_H
#define NECK_12_H

#include "equipment.h"

class Neck_12 : public Equipment { // 奔流不息之山川 Neck: 0
  public:
    Neck_12() {}
	void operator() (Character &model);
};

#endif // NECK_12_H
