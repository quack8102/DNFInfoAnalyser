#ifndef NECK_21_H
#define NECK_21_H

#include "equipment.h"

class Neck_21 : public Equipment { // 千蛛碎影之蛛丝肩甲 Neck: 0
  public:
    Neck_21() {}
	void operator() (Character &model);
};

#endif // NECK_21_H
