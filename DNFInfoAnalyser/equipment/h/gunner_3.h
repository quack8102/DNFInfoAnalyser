#ifndef GUNNER_3_H
#define GUNNER_3_H

#include "equipment.h"

class Gunner_3 : public Equipment { // 午夜生死轮盘 Gunner: 5
  public:
    Gunner_3() {}
	void operator() (Character &model);
};

#endif // GUNNER_3_H
