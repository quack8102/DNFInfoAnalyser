#ifndef SET_6_H
#define SET_6_H

#include "equipment.h"

class Set_6 : public Equipment { // 龙血玄黄
  public:
    Set_6() {}
	void operator() (Character &model);
};

#endif // SET_6_H
