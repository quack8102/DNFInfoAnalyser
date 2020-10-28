#ifndef PANTS_0_H
#define PANTS_0_H

#include "equipment.h"

class Pants_0 : public Equipment { // 大祭司的星祈长裙 Pants: 2
  public:
    Pants_0() {}
	void operator() (Character &model);
};

#endif // PANTS_0_H
