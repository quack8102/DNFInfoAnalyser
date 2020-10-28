#ifndef BELT_9_H
#define BELT_9_H

#include "equipment.h"

class Belt_9 : public Equipment { // 亚巴顿：绝望地狱 Belt: 3
  public:
    Belt_9() {}
	void operator() (Character &model);
};

#endif // BELT_9_H
