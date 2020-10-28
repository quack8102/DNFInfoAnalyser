#ifndef SET_20_H
#define SET_20_H

#include "equipment.h"

class Set_20 : public Equipment { // 军神的隐秘遗产
  public:
    Set_20() {}
	void operator() (Character &model);
};

#endif // SET_20_H
