#ifndef NECK_14_H
#define NECK_14_H

#include "equipment.h"

class Neck_14 : public Equipment { // 猛烈燃烧之炎 Neck: 0
  public:
    Neck_14() {}
	void operator() (Character &model);
};

#endif // NECK_14_H
