#ifndef GUNNER_21_H
#define GUNNER_21_H

#include "equipment.h"

class Gunner_21 : public Equipment { // 界·夜语黑瞳手弩 Gunner: 5
  public:
    Gunner_21() {}
	void operator() (Character &model);
};

#endif // GUNNER_21_H
