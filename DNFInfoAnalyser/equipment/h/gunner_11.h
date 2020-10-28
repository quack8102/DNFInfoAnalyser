#ifndef GUNNER_11_H
#define GUNNER_11_H

#include "equipment.h"

class Gunner_11 : public Equipment { // 界·夜语黑瞳步枪 Gunner: 5
  public:
    Gunner_11() {}
	void operator() (Character &model);
};

#endif // GUNNER_11_H
