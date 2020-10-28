#ifndef THIEF_2_H
#define THIEF_2_H

#include "equipment.h"

class Thief_2 : public Equipment { // 暗黑圣战之溯回：匕首 Thief: 5
  public:
    Thief_2() {}
	void operator() (Character &model);
};

#endif // THIEF_2_H
