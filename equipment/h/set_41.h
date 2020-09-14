#ifndef SET_41_H
#define SET_41_H

#include "equipment.h"

class Set_41 : public Equipment { // 天御之灾
  public:
    Set_41() {}
	void operator() (Character &model);
};

#endif // SET_41_H
