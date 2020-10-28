#ifndef GUNNER_15_H
#define GUNNER_15_H

#include "equipment.h"

class Gunner_15 : public Equipment { // 夜语黑瞳手炮 Gunner: 5
  public:
    Gunner_15() {}
	void operator() (Character &model);
};

#endif // GUNNER_15_H
