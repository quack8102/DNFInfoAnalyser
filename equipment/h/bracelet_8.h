#ifndef BRACELET_8_H
#define BRACELET_8_H

#include "equipment.h"

class Bracelet_8 : public Equipment { // 莱多：变幻的规律 Bracelet: 7
  public:
    Bracelet_8() {}
	void operator() (Character &model);
};

#endif // BRACELET_8_H
