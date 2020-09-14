#ifndef PRIEST_15_H
#define PRIEST_15_H

#include "equipment.h"

class Priest_15 : public Equipment { // 夜语黑瞳镰刀 Priest: 5
  public:
    Priest_15() {}
	void operator() (Character &model);
};

#endif // PRIEST_15_H
