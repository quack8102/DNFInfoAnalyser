#ifndef SET_33_H
#define SET_33_H

#include "equipment.h"

class Set_33 : public Equipment { // 次元旅行者
  public:
    Set_33() {}
	void operator() (Character &model);
};

#endif // SET_33_H
