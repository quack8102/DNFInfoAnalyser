#ifndef THIEF_1_H
#define THIEF_1_H

#include "equipment.h"

class Thief_1 : public Equipment { // 界·夜语黑瞳匕首 Thief: 5
  public:
    Thief_1() {}
	void operator() (Character &model);
};

#endif // THIEF_1_H
