#ifndef THIEF_3_H
#define THIEF_3_H

#include "equipment.h"

class Thief_3 : public Equipment { // 匿影 Thief: 5
  public:
    Thief_3() {}
	void operator() (Character &model);
};

#endif // THIEF_3_H
