#ifndef BRACELET_12_H
#define BRACELET_12_H

#include "equipment.h"

class Bracelet_12 : public Equipment { // 执着的探求 Bracelet: 7
  public:
    Bracelet_12() {}
	void operator() (Character &model);
};

#endif // BRACELET_12_H
