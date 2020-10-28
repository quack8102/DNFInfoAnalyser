#ifndef THIEF_15_H
#define THIEF_15_H

#include "equipment.h"

class Thief_15 : public Equipment { // 夜语黑瞳苦无 Thief: 5
  public:
    Thief_15() {}
	void operator() (Character &model);
};

#endif // THIEF_15_H
