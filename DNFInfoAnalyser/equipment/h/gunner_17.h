#ifndef GUNNER_17_H
#define GUNNER_17_H

#include "equipment.h"

class Gunner_17 : public Equipment { // 暗黑圣战之溯回：手炮 Gunner: 5
  public:
    Gunner_17() {}
	void operator() (Character &model);
};

#endif // GUNNER_17_H
