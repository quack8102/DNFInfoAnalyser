#ifndef THIEF_14_H
#define THIEF_14_H

#include "equipment.h"

class Thief_14 : public Equipment { // 圣洁的精灵遗物 Thief: 5
  public:
    Thief_14() {}
	void operator() (Character &model);
};

#endif // THIEF_14_H
