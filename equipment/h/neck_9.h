#ifndef NECK_9_H
#define NECK_9_H

#include "equipment.h"

class Neck_9 : public Equipment { // 贝利亚尔：毁灭之种 Neck: 0
  public:
    Neck_9() {}
	void operator() (Character &model);
};

#endif // NECK_9_H
