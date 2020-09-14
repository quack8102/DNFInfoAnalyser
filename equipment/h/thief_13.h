#ifndef THIEF_13_H
#define THIEF_13_H

#include "equipment.h"

class Thief_13 : public Equipment { // 绿色生命的面容 Thief: 5
  public:
    Thief_13() {}
	void operator() (Character &model);
};

#endif // THIEF_13_H
