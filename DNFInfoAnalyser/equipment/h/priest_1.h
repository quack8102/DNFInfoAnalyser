#ifndef PRIEST_1_H
#define PRIEST_1_H

#include "equipment.h"

class Priest_1 : public Equipment { // 界·夜语黑瞳十字架 Priest: 5
  public:
    Priest_1() {}
	void operator() (Character &model);
};

#endif // PRIEST_1_H
