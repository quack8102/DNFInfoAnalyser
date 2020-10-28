#ifndef PRIEST_4_H
#define PRIEST_4_H

#include "equipment.h"

class Priest_4 : public Equipment { // 闪耀的神威 Priest: 5
  public:
    Priest_4() {}
	void operator() (Character &model);
};

#endif // PRIEST_4_H
