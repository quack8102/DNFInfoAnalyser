#ifndef GUNNER_22_H
#define GUNNER_22_H

#include "equipment.h"

class Gunner_22 : public Equipment { // 暗黑圣战之溯回：手弩 Gunner: 5
  public:
    Gunner_22() {}
	void operator() (Character &model);
};

#endif // GUNNER_22_H
