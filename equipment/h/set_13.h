#ifndef SET_13_H
#define SET_13_H

#include "equipment.h"

class Set_13 : public Equipment { // 永恒不息之路
  public:
    Set_13() {}
	void operator() (Character &model);
};

#endif // SET_13_H
