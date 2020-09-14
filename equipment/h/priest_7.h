#ifndef PRIEST_7_H
#define PRIEST_7_H

#include "equipment.h"

class Priest_7 : public Equipment { // 暗黑圣战之溯回：念珠 Priest: 5
  public:
    Priest_7() {}
	void operator() (Character &model);
};

#endif // PRIEST_7_H
