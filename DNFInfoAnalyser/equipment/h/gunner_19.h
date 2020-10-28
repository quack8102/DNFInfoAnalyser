#ifndef GUNNER_19_H
#define GUNNER_19_H

#include "equipment.h"

class Gunner_19 : public Equipment { // 绝杀：无人生还 Gunner: 5
  public:
    Gunner_19() {}
	void operator() (Character &model);
};

#endif // GUNNER_19_H
