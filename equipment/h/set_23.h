#ifndef SET_23_H
#define SET_23_H

#include "equipment.h"

class Set_23 : public Equipment { // 能量主宰
  public:
    Set_23() {}
	void operator() (Character &model);
};

#endif // SET_23_H
