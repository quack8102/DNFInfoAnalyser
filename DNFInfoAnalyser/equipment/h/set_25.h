#ifndef SET_25_H
#define SET_25_H

#include "equipment.h"

class Set_25 : public Equipment { // 圣者的黄昏
  public:
    Set_25() {}
	void operator() (Character &model);
};

#endif // SET_25_H
