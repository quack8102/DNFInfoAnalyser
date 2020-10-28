#ifndef NECK_6_H
#define NECK_6_H

#include "equipment.h"

class Neck_6 : public Equipment { // 艰难求生之斗志 Neck: 0
  public:
    Neck_6() {}
	void operator() (Character &model);
};

#endif // NECK_6_H
