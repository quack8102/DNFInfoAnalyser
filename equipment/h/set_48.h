#ifndef SET_48_H
#define SET_48_H

#include "equipment.h"

class Set_48 : public Equipment { // 精炼的异界魔石首饰
  public:
    Set_48() {}
	void operator() (Character &model);
};

#endif // SET_48_H
