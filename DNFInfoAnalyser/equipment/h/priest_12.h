#ifndef PRIEST_12_H
#define PRIEST_12_H

#include "equipment.h"

class Priest_12 : public Equipment { // 暗黑圣战之溯回：图腾 Priest: 5
  public:
    Priest_12() {}
	void operator() (Character &model);
};

#endif // PRIEST_12_H
