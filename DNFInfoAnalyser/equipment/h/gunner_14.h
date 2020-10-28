#ifndef GUNNER_14_H
#define GUNNER_14_H

#include "equipment.h"

class Gunner_14 : public Equipment { // 强力打击-X Gunner: 5
  public:
    Gunner_14() {}
	void operator() (Character &model);
};

#endif // GUNNER_14_H
