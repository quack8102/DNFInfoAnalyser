#ifndef COAT_48_H
#define COAT_48_H

#include "equipment.h"

class Coat_48 : public Equipment { // 霸域英豪胸甲 Coat: 1
  public:
    Coat_48() {}
	void operator() (Character &model);
};

#endif // COAT_48_H
