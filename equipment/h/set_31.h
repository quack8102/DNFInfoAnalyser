#ifndef SET_31_H
#define SET_31_H

#include "equipment.h"

class Set_31 : public Equipment { // 狂乱追随者
  public:
    Set_31() {}
	void operator() (Character &model);
};

#endif // SET_31_H
