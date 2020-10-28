#ifndef NECK_20_H
#define NECK_20_H

#include "equipment.h"

class Neck_20 : public Equipment { // 誓血之盟肩甲 Neck: 0
  public:
    Neck_20() {}
	void operator() (Character &model);
};

#endif // NECK_20_H
