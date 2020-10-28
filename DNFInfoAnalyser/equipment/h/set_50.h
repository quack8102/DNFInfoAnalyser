#ifndef SET_50_H
#define SET_50_H

#include "equipment.h"

class Set_50 : public Equipment { // 万物的生灭
  public:
    Set_50() {}
	void operator() (Character &model);
};

#endif // SET_50_H
