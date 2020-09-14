#ifndef SET_10_H
#define SET_10_H

#include "equipment.h"

class Set_10 : public Equipment { // 噩梦：地狱之路
  public:
    Set_10() {}
	void operator() (Character &model);
};

#endif // SET_10_H
