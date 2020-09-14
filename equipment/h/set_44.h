#ifndef SET_44_H
#define SET_44_H

#include "equipment.h"

class Set_44 : public Equipment { // 千蛛碎影
  public:
    Set_44() {}
	void operator() (Character &model);
};

#endif // SET_44_H
