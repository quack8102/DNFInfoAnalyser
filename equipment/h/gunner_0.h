#ifndef GUNNER_0_H
#define GUNNER_0_H

#include "equipment.h"

class Gunner_0 : public Equipment { // 夜语黑瞳左轮枪 Gunner: 5
  public:
    Gunner_0() {}
	void operator() (Character &model);
};

#endif // GUNNER_0_H
