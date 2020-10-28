#ifndef THIEF_5_H
#define THIEF_5_H

#include "equipment.h"

class Thief_5 : public Equipment { // 夜语黑瞳双剑 Thief: 5
  public:
    Thief_5() {}
	void operator() (Character &model);
};

#endif // THIEF_5_H
