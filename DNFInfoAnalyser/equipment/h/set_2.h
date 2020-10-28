#ifndef SET_2_H
#define SET_2_H

#include "equipment.h"

class Set_2 : public Equipment { // 遗忘魔法师的馈赠
  public:
    Set_2() {}
	void operator() (Character &model);
};

#endif // SET_2_H
