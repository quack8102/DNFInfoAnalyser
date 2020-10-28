#ifndef SET_5_H
#define SET_5_H

#include "equipment.h"

class Set_5 : public Equipment { // 皇家裁决者宣言
  public:
    Set_5() {}
	void operator() (Character &model);
};

#endif // SET_5_H
