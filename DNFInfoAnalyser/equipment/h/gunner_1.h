#ifndef GUNNER_1_H
#define GUNNER_1_H

#include "equipment.h"

class Gunner_1 : public Equipment { // 界·夜语黑瞳左轮枪 Gunner: 5
  public:
    Gunner_1() {}
	void operator() (Character &model);
};

#endif // GUNNER_1_H
