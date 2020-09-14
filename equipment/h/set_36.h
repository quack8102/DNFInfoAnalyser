#ifndef SET_36_H
#define SET_36_H

#include "equipment.h"

class Set_36 : public Equipment { // 堕落的黑暗之力
  public:
    Set_36() {}
	void operator() (Character &model);
};

#endif // SET_36_H
