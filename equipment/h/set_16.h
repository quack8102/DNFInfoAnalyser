#ifndef SET_16_H
#define SET_16_H

#include "equipment.h"

class Set_16 : public Equipment { // 上古尘封术士
  public:
    Set_16() {}
	void operator() (Character &model);
};

#endif // SET_16_H
