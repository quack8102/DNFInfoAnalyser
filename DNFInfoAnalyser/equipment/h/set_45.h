#ifndef SET_45_H
#define SET_45_H

#include "equipment.h"

class Set_45 : public Equipment { // 魔战无双
  public:
    Set_45() {}
	void operator() (Character &model);
};

#endif // SET_45_H
