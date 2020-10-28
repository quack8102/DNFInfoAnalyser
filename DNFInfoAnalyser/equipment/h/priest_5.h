#ifndef PRIEST_5_H
#define PRIEST_5_H

#include "equipment.h"

class Priest_5 : public Equipment { // 夜语黑瞳念珠 Priest: 5
  public:
    Priest_5() {}
	void operator() (Character &model);
};

#endif // PRIEST_5_H
