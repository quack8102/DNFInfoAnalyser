#ifndef SET_34_H
#define SET_34_H

#include "equipment.h"

class Set_34 : public Equipment { // 天命无常
  public:
    Set_34() {}
	void operator() (Character &model);
};

#endif // SET_34_H
