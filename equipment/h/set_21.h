#ifndef SET_21_H
#define SET_21_H

#include "equipment.h"

class Set_21 : public Equipment { // 灵宝：世间真理
  public:
    Set_21() {}
	void operator() (Character &model);
};

#endif // SET_21_H
