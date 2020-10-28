#ifndef SET_15_H
#define SET_15_H

#include "equipment.h"

class Set_15 : public Equipment { // 大自然的呼吸
  public:
    Set_15() {}
	void operator() (Character &model);
};

#endif // SET_15_H
