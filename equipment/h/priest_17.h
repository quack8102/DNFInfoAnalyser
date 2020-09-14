#ifndef PRIEST_17_H
#define PRIEST_17_H

#include "equipment.h"

class Priest_17 : public Equipment { // 暗黑圣战之溯回：镰刀 Priest: 5
  public:
    Priest_17() {}
	void operator() (Character &model);
};

#endif // PRIEST_17_H
