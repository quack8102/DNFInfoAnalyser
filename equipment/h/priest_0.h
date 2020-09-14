#ifndef PRIEST_0_H
#define PRIEST_0_H

#include "equipment.h"

class Priest_0 : public Equipment { // 夜语黑瞳十字架 Priest: 5
  public:
    Priest_0() {}
	void operator() (Character &model);
};

#endif // PRIEST_0_H
