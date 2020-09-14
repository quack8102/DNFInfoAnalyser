#ifndef SET_28_H
#define SET_28_H

#include "equipment.h"

class Set_28 : public Equipment { // 黑魔法探求者
  public:
    Set_28() {}
	void operator() (Character &model);
};

#endif // SET_28_H
