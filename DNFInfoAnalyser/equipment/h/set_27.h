#ifndef SET_27_H
#define SET_27_H

#include "equipment.h"

class Set_27 : public Equipment { // 吞噬愤怒
  public:
    Set_27() {}
	void operator() (Character &model);
};

#endif // SET_27_H
