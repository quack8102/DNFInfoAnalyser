#ifndef BRACELET_6_H
#define BRACELET_6_H

#include "equipment.h"

class Bracelet_6 : public Equipment { // 响彻天地的咆哮 Bracelet: 7
  public:
    Bracelet_6() {}
	void operator() (Character &model);
};

#endif // BRACELET_6_H
