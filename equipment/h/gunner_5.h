#ifndef GUNNER_5_H
#define GUNNER_5_H

#include "equipment.h"

class Gunner_5 : public Equipment { // 夜语黑瞳自动手枪 Gunner: 5
  public:
    Gunner_5() {}
	void operator() (Character &model);
};

#endif // GUNNER_5_H
