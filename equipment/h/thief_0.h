#ifndef THIEF_0_H
#define THIEF_0_H

#include "equipment.h"

class Thief_0 : public Equipment { // 夜语黑瞳匕首 Thief: 5
  public:
    Thief_0() {}
	void operator() (Character &model);
};

#endif // THIEF_0_H
