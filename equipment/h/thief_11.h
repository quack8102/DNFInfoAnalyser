#ifndef THIEF_11_H
#define THIEF_11_H

#include "equipment.h"

class Thief_11 : public Equipment { // 界·夜语黑瞳手杖 Thief: 5
  public:
    Thief_11() {}
	void operator() (Character &model);
};

#endif // THIEF_11_H
