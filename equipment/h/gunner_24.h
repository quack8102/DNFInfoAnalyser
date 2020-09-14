#ifndef GUNNER_24_H
#define GUNNER_24_H

#include "equipment.h"

class Gunner_24 : public Equipment { // 吟游诗人的轻吟 Gunner: 5
  public:
    Gunner_24() {}
	void operator() (Character &model);
};

#endif // GUNNER_24_H
