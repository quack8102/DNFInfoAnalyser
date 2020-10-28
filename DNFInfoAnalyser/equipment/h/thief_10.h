#ifndef THIEF_10_H
#define THIEF_10_H

#include "equipment.h"

class Thief_10 : public Equipment { // 夜语黑瞳手杖 Thief: 5
  public:
    Thief_10() {}
	void operator() (Character &model);
};

#endif // THIEF_10_H
