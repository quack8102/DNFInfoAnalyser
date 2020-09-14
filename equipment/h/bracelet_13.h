#ifndef BRACELET_13_H
#define BRACELET_13_H

#include "equipment.h"

class Bracelet_13 : public Equipment { // 时间指引之针 Bracelet: 7
  public:
    Bracelet_13() {}
	void operator() (Character &model);
};

#endif // BRACELET_13_H
