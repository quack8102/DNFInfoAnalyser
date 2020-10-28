#ifndef SET_22_H
#define SET_22_H

#include "equipment.h"

class Set_22 : public Equipment { // 时间战争的残骸
  public:
    Set_22() {}
	void operator() (Character &model);
};

#endif // SET_22_H
