#ifndef BELT_19_H
#define BELT_19_H

#include "equipment.h"

class Belt_19 : public Equipment { // 最佳球手的冲锋腰带 Belt: 3
  public:
    Belt_19() {}
	void operator() (Character &model);
};

#endif // BELT_19_H
