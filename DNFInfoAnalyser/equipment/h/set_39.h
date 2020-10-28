#ifndef SET_39_H
#define SET_39_H

#include "equipment.h"

class Set_39 : public Equipment { // 逝魔之力
  public:
    Set_39() {}
	void operator() (Character &model);
};

#endif // SET_39_H
