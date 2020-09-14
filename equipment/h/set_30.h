#ifndef SET_30_H
#define SET_30_H

#include "equipment.h"

class Set_30 : public Equipment { // 穿透命运的呐喊
  public:
    Set_30() {}
	void operator() (Character &model);
};

#endif // SET_30_H
