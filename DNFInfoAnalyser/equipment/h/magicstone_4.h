#ifndef MAGICSTONE_4_H
#define MAGICSTONE_4_H

#include "equipment.h"

class Magicstone_4 : public Equipment { // 暗黑术士的精髓 Magicstone: 12
  public:
    Magicstone_4() {}
	void operator() (Character &model);
};

#endif // MAGICSTONE_4_H
