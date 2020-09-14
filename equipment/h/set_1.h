#ifndef SET_1_H
#define SET_1_H

#include "equipment.h"

class Set_1 : public Equipment { // 古代祭祀的神圣仪式
  public:
    Set_1() {}
	void operator() (Character &model);
};

#endif // SET_1_H
