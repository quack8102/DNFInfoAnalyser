#ifndef NECK_11_H
#define NECK_11_H

#include "equipment.h"

class Neck_11 : public Equipment { // 千链锁灵肩甲 Neck: 0
  public:
    Neck_11() {}
	void operator() (Character &model);
};

#endif // NECK_11_H
