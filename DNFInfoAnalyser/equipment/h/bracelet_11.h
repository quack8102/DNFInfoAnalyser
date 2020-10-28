#ifndef BRACELET_11_H
#define BRACELET_11_H

#include "equipment.h"

class Bracelet_11 : public Equipment { // 火魔之焰-沙罗曼达 Bracelet: 7
  public:
    Bracelet_11() {}
	void operator() (Character &model);
};

#endif // BRACELET_11_H
