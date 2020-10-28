#ifndef BRACELET_5_H
#define BRACELET_5_H

#include "equipment.h"

class Bracelet_5 : public Equipment { // 时间回溯之针 Bracelet: 7
  public:
    Bracelet_5() {}
	void operator() (Character &model);
};

#endif // BRACELET_5_H
