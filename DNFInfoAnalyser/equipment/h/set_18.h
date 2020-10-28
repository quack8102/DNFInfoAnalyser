#ifndef SET_18_H
#define SET_18_H

#include "equipment.h"

class Set_18 : public Equipment { // 幸运三角
  public:
    Set_18() {}
	void operator() (Character &model);
};

#endif // SET_18_H
