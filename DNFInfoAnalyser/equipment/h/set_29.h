#ifndef SET_29_H
#define SET_29_H

#include "equipment.h"

class Set_29 : public Equipment { // 时空旅行者
  public:
    Set_29() {}
	void operator() (Character &model);
};

#endif // SET_29_H
