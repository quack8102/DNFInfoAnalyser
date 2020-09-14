#ifndef SET_24_H
#define SET_24_H

#include "equipment.h"

class Set_24 : public Equipment { // 深渊窥视者
  public:
    Set_24() {}
	void operator() (Character &model);
};

#endif // SET_24_H
