#ifndef GUNNER_4_H
#define GUNNER_4_H

#include "equipment.h"

class Gunner_4 : public Equipment { // 血枪之脉 Gunner: 5
  public:
    Gunner_4() {}
	void operator() (Character &model);
};

#endif // GUNNER_4_H
