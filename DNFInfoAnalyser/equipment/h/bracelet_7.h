#ifndef BRACELET_7_H
#define BRACELET_7_H

#include "equipment.h"

class Bracelet_7 : public Equipment { // 狂乱之逆转宿命 Bracelet: 7
  public:
    Bracelet_7() {}
	void operator() (Character &model);
};

#endif // BRACELET_7_H
