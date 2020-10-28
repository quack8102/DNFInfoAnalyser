#ifndef GUNNER_7_H
#define GUNNER_7_H

#include "equipment.h"

class Gunner_7 : public Equipment { // 暗黑圣战之溯回：自动手枪 Gunner: 5
  public:
    Gunner_7() {}
	void operator() (Character &model);
};

#endif // GUNNER_7_H
