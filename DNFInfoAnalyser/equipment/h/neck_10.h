#ifndef NECK_10_H
#define NECK_10_H

#include "equipment.h"

class Neck_10 : public Equipment { // 魔龙之心 Neck: 0
  public:
    Neck_10() {}
	void operator() (Character &model);
};

#endif // NECK_10_H
