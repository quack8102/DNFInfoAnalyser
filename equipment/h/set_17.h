#ifndef SET_17_H
#define SET_17_H

#include "equipment.h"

class Set_17 : public Equipment { // 破晓曦光
  public:
    Set_17() {}
	void operator() (Character &model);
};

#endif // SET_17_H
