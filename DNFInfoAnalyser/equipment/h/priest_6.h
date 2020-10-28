#ifndef PRIEST_6_H
#define PRIEST_6_H

#include "equipment.h"

class Priest_6 : public Equipment { // 界·夜语黑瞳念珠 Priest: 5
  public:
    Priest_6() {}
	void operator() (Character &model);
};

#endif // PRIEST_6_H
