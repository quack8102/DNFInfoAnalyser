#ifndef SWORDMAN_11_H
#define SWORDMAN_11_H

#include "equipment.h"

class Swordman_11 : public Equipment { // 界·夜语黑瞳钝器 Swordman: 5
  public:
    Swordman_11() {}
	void operator() (Character &model);
};

#endif // SWORDMAN_11_H
