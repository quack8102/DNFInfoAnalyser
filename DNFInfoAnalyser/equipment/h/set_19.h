#ifndef SET_19_H
#define SET_19_H

#include "equipment.h"

class Set_19 : public Equipment { // 精灵使的权能
  public:
    Set_19() {}
	void operator() (Character &model);
};

#endif // SET_19_H
