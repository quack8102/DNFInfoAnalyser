#ifndef GUNNER_23_H
#define GUNNER_23_H

#include "equipment.h"

class Gunner_23 : public Equipment { // 激光流星弓 Gunner: 5
  public:
    Gunner_23() {}
	void operator() (Character &model);
};

#endif // GUNNER_23_H
