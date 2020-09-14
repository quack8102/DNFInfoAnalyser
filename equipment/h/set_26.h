#ifndef SET_26_H
#define SET_26_H

#include "equipment.h"

class Set_26 : public Equipment { // 坎坷命运
  public:
    Set_26() {}
	void operator() (Character &model);
};

#endif // SET_26_H
