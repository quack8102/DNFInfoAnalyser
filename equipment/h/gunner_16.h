#ifndef GUNNER_16_H
#define GUNNER_16_H

#include "equipment.h"

class Gunner_16 : public Equipment { // 界·夜语黑瞳手炮 Gunner: 5
  public:
    Gunner_16() {}
	void operator() (Character &model);
};

#endif // GUNNER_16_H
