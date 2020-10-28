#ifndef PRIEST_22_H
#define PRIEST_22_H

#include "equipment.h"

class Priest_22 : public Equipment { // 暗黑圣战之溯回：战斧 Priest: 5
  public:
    Priest_22() {}
	void operator() (Character &model);
};

#endif // PRIEST_22_H
