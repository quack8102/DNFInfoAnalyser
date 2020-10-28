#ifndef BRACELET_15_H
#define BRACELET_15_H

#include "equipment.h"

class Bracelet_15 : public Equipment { // 狂乱之坚如磐石 Bracelet: 7
  public:
    Bracelet_15() {}
	void operator() (Character &model);
};

#endif // BRACELET_15_H
