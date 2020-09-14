#ifndef SET_11_H
#define SET_11_H

#include "equipment.h"

class Set_11 : public Equipment { // 传奇铁匠-封神
  public:
    Set_11() {}
	void operator() (Character &model);
};

#endif // SET_11_H
