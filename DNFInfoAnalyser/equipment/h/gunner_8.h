#ifndef GUNNER_8_H
#define GUNNER_8_H

#include "equipment.h"

class Gunner_8 : public Equipment { // 寻觅海石竹 Gunner: 5
  public:
    Gunner_8() {}
	void operator() (Character &model);
};

#endif // GUNNER_8_H
