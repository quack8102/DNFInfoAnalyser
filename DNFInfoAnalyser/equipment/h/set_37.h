#ifndef SET_37_H
#define SET_37_H

#include "equipment.h"

class Set_37 : public Equipment { // 维度崩坏
  public:
    Set_37() {}
	void operator() (Character &model);
};

#endif // SET_37_H
