#ifndef PANTS_10_H
#define PANTS_10_H

#include "equipment.h"

class Pants_10 : public Equipment { // 邪恶之角 Pants: 2
  public:
    Pants_10() {}
	void operator() (Character &model);
};

#endif // PANTS_10_H
