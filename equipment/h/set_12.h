#ifndef SET_12_H
#define SET_12_H

#include "equipment.h"

class Set_12 : public Equipment { // 荆棘漫天
  public:
    Set_12() {}
	void operator() (Character &model);
};

#endif // SET_12_H
