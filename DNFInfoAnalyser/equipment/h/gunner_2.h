#ifndef GUNNER_2_H
#define GUNNER_2_H

#include "equipment.h"

class Gunner_2 : public Equipment { // 暗黑圣战之溯回：左轮枪 Gunner: 5
  public:
    Gunner_2() {}
	void operator() (Character &model);
};

#endif // GUNNER_2_H
