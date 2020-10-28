#ifndef SET_40_H
#define SET_40_H

#include "equipment.h"

class Set_40 : public Equipment { // 杀意决
  public:
    Set_40() {}
	void operator() (Character &model);
};

#endif // SET_40_H
