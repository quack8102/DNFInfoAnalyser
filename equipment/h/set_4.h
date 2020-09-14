#ifndef SET_4_H
#define SET_4_H

#include "equipment.h"

class Set_4 : public Equipment { // 死亡阴影
  public:
    Set_4() {}
	void operator() (Character &model);
};

#endif // SET_4_H
