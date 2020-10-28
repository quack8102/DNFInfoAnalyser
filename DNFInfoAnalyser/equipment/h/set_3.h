#ifndef SET_3_H
#define SET_3_H

#include "equipment.h"

class Set_3 : public Equipment { // 天堂舞姬
  public:
    Set_3() {}
	void operator() (Character &model);
};

#endif // SET_3_H
