#ifndef GUNNER_20_H
#define GUNNER_20_H

#include "equipment.h"

class Gunner_20 : public Equipment { // 夜语黑瞳手弩 Gunner: 5
  public:
    Gunner_20() {}
	void operator() (Character &model);
};

#endif // GUNNER_20_H
