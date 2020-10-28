#ifndef PRIEST_2_H
#define PRIEST_2_H

#include "equipment.h"

class Priest_2 : public Equipment { // 暗黑圣战之溯回：十字架 Priest: 5
  public:
    Priest_2() {}
	void operator() (Character &model);
};

#endif // PRIEST_2_H
