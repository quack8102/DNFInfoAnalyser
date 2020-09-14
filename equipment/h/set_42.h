#ifndef SET_42_H
#define SET_42_H

#include "equipment.h"

class Set_42 : public Equipment { // 最佳球手的绝杀
  public:
    Set_42() {}
	void operator() (Character &model);
};

#endif // SET_42_H
