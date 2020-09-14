#ifndef BRACELET_19_H
#define BRACELET_19_H

#include "equipment.h"

class Bracelet_19 : public Equipment { // 冰雪公主的霜语手镯 Bracelet: 7
  public:
    Bracelet_19() {}
	void operator() (Character &model);
};

#endif // BRACELET_19_H
