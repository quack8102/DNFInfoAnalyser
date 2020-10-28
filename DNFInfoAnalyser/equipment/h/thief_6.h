#ifndef THIEF_6_H
#define THIEF_6_H

#include "equipment.h"

class Thief_6 : public Equipment { // 界·夜语黑瞳双剑 Thief: 5
  public:
    Thief_6() {}
	void operator() (Character &model);
};

#endif // THIEF_6_H
