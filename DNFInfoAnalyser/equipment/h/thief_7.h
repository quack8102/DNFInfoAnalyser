#ifndef THIEF_7_H
#define THIEF_7_H

#include "equipment.h"

class Thief_7 : public Equipment { // 暗黑圣战之溯回：双剑 Thief: 5
  public:
    Thief_7() {}
	void operator() (Character &model);
};

#endif // THIEF_7_H
