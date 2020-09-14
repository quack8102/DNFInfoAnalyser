#ifndef BRACELET_14_H
#define BRACELET_14_H

#include "equipment.h"

class Bracelet_14 : public Equipment { // 支配战场的呐喊 Bracelet: 7
  public:
    Bracelet_14() {}
	void operator() (Character &model);
};

#endif // BRACELET_14_H
