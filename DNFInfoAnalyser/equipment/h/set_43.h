#ifndef SET_43_H
#define SET_43_H

#include "equipment.h"

class Set_43 : public Equipment { // 誓血之盟
  public:
    Set_43() {}
	void operator() (Character &model);
};

#endif // SET_43_H
