#ifndef PANTS_17_H
#define PANTS_17_H

#include "equipment.h"

class Pants_17 : public Equipment { // 灵魂的呐喊 Pants: 2
  public:
    Pants_17() {}
	void operator() (Character &model);
};

#endif // PANTS_17_H
