#ifndef THIEF_12_H
#define THIEF_12_H

#include "equipment.h"

class Thief_12 : public Equipment { // 暗黑圣战之溯回：手杖 Thief: 5
  public:
    Thief_12() {}
	void operator() (Character &model);
};

#endif // THIEF_12_H
