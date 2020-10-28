#ifndef BRACELET_1_H
#define BRACELET_1_H

#include "equipment.h"

class Bracelet_1 : public Equipment { // 融化黑暗之温暖 Bracelet: 7
  public:
    Bracelet_1() {}
	void operator() (Character &model);
};

#endif // BRACELET_1_H
