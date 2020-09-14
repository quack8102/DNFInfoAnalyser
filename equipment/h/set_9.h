#ifndef SET_9_H
#define SET_9_H

#include "equipment.h"

class Set_9 : public Equipment { // 擎天战甲
  public:
    Set_9() {}
	void operator() (Character &model);
};

#endif // SET_9_H
