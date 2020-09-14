#ifndef NECK_13_H
#define NECK_13_H

#include "equipment.h"

class Neck_13 : public Equipment { // 矛盾的抉择 Neck: 0
  public:
    Neck_13() {}
	void operator() (Character &model);
};

#endif // NECK_13_H
