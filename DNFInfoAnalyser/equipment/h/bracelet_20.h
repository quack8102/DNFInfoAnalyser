#ifndef BRACELET_20_H
#define BRACELET_20_H

#include "equipment.h"

class Bracelet_20 : public Equipment { // 精炼的毁伤魔石手环 Bracelet: 7
  public:
    Bracelet_20() {}
	void operator() (Character &model);
};

#endif // BRACELET_20_H
