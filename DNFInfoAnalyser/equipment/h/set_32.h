#ifndef SET_32_H
#define SET_32_H

#include "equipment.h"

class Set_32 : public Equipment { // 地狱求道者
  public:
    Set_32() {}
	void operator() (Character &model);
};

#endif // SET_32_H
