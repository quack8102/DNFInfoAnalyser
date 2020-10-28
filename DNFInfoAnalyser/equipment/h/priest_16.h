#ifndef PRIEST_16_H
#define PRIEST_16_H

#include "equipment.h"

class Priest_16 : public Equipment { // 界·夜语黑瞳镰刀 Priest: 5
  public:
    Priest_16() {}
	void operator() (Character &model);
};

#endif // PRIEST_16_H
