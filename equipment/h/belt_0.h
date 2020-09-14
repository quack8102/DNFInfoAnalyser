#ifndef BELT_0_H
#define BELT_0_H

#include "equipment.h"

class Belt_0 : public Equipment { // 大祭司的星祈腰带 Belt: 3
  public:
    Belt_0() {}
	void operator() (Character &model);
};

#endif // BELT_0_H
