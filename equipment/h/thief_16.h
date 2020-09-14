#ifndef THIEF_16_H
#define THIEF_16_H

#include "equipment.h"

class Thief_16 : public Equipment { // 界·夜语黑瞳苦无 Thief: 5
  public:
    Thief_16() {}
	void operator() (Character &model);
};

#endif // THIEF_16_H
