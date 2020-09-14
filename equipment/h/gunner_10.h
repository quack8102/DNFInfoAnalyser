#ifndef GUNNER_10_H
#define GUNNER_10_H

#include "equipment.h"

class Gunner_10 : public Equipment { // 夜语黑瞳步枪 Gunner: 5
  public:
    Gunner_10() {}
	void operator() (Character &model);
};

#endif // GUNNER_10_H
