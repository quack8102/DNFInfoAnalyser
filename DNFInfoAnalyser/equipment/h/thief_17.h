#ifndef THIEF_17_H
#define THIEF_17_H

#include "equipment.h"

class Thief_17 : public Equipment { // 暗黑圣战之溯回：苦无 Thief: 5
  public:
    Thief_17() {}
	void operator() (Character &model);
};

#endif // THIEF_17_H
