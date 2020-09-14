#ifndef THIEF_8_H
#define THIEF_8_H

#include "equipment.h"

class Thief_8 : public Equipment { // 一叶障目 Thief: 5
  public:
    Thief_8() {}
	void operator() (Character &model);
};

#endif // THIEF_8_H
