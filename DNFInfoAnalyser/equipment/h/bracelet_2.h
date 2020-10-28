#ifndef BRACELET_2_H
#define BRACELET_2_H

#include "equipment.h"

class Bracelet_2 : public Equipment { // 伽内什的永恒庇护 Bracelet: 7
  public:
    Bracelet_2() {}
	void operator() (Character &model);
};

#endif // BRACELET_2_H
