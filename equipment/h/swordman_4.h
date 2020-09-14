#ifndef SWORDMAN_4_H
#define SWORDMAN_4_H

#include "equipment.h"

class Swordman_4 : public Equipment { // 战场的热血：安格巴迪 Swordman: 5
  public:
    Swordman_4() {}
	void operator() (Character &model);
};

#endif // SWORDMAN_4_H
