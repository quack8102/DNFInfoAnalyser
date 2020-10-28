#ifndef GUNNER_6_H
#define GUNNER_6_H

#include "equipment.h"

class Gunner_6 : public Equipment { // 界·夜语黑瞳自动手枪 Gunner: 5
  public:
    Gunner_6() {}
	void operator() (Character &model);
};

#endif // GUNNER_6_H
