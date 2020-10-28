#ifndef GUNNER_18_H
#define GUNNER_18_H

#include "equipment.h"

class Gunner_18 : public Equipment { // 乾坤极电炮 Gunner: 5
  public:
    Gunner_18() {}
	void operator() (Character &model);
};

#endif // GUNNER_18_H
