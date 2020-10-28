#ifndef PRIEST_3_H
#define PRIEST_3_H

#include "equipment.h"

class Priest_3 : public Equipment { // 圣者的慈悲 Priest: 5
  public:
    Priest_3() {}
	void operator() (Character &model);
};

#endif // PRIEST_3_H
