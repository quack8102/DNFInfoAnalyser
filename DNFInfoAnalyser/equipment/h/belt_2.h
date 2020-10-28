#ifndef BELT_2_H
#define BELT_2_H

#include "equipment.h"

class Belt_2 : public Equipment { // 热情舞动桑巴 Belt: 3
  public:
    Belt_2() {}
	void operator() (Character &model);
};

#endif // BELT_2_H
