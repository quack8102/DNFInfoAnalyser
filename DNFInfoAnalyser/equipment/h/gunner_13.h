#ifndef GUNNER_13_H
#define GUNNER_13_H

#include "equipment.h"

class Gunner_13 : public Equipment { // 湍流 Gunner: 5
  public:
    Gunner_13() {}
	void operator() (Character &model);
};

#endif // GUNNER_13_H
