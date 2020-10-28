#ifndef SET_46_H
#define SET_46_H

#include "equipment.h"

class Set_46 : public Equipment { // 霸域英豪
  public:
    Set_46() {}
	void operator() (Character &model);
};

#endif // SET_46_H
