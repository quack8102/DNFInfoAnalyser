#ifndef SET_7_H
#define SET_7_H

#include "equipment.h"

class Set_7 : public Equipment { // 贫瘠沙漠的遗产
  public:
    Set_7() {}
	void operator() (Character &model);
};

#endif // SET_7_H
