#ifndef NECK_2_H
#define NECK_2_H

#include "equipment.h"

class Neck_2 : public Equipment { // 性感洒脱探戈 Neck: 0
  public:
    Neck_2() {}
	void operator() (Character &model);
};

#endif // NECK_2_H
