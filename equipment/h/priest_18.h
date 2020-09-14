#ifndef PRIEST_18_H
#define PRIEST_18_H

#include "equipment.h"

class Priest_18 : public Equipment { // 泯灭之灵 Priest: 5
  public:
    Priest_18() {}
	void operator() (Character &model);
};

#endif // PRIEST_18_H
