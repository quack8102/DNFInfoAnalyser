#ifndef SET_14_H
#define SET_14_H

#include "equipment.h"

class Set_14 : public Equipment { // 命运歧路
  public:
    Set_14() {}
	void operator() (Character &model);
};

#endif // SET_14_H
