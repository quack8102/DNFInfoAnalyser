#ifndef PRIEST_8_H
#define PRIEST_8_H

#include "equipment.h"

class Priest_8 : public Equipment { // 轮回之环：桓龙 Priest: 5
  public:
    Priest_8() {}
	void operator() (Character &model);
};

#endif // PRIEST_8_H
