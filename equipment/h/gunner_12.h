#ifndef GUNNER_12_H
#define GUNNER_12_H

#include "equipment.h"

class Gunner_12 : public Equipment { // 暗黑圣战之溯回：步枪 Gunner: 5
  public:
    Gunner_12() {}
	void operator() (Character &model);
};

#endif // GUNNER_12_H
