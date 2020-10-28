#ifndef MAGICSTONE_8_H
#define MAGICSTONE_8_H

#include "equipment.h"

class Magicstone_8 : public Equipment { // 腐蚀之黑色尖角 Magicstone: 12
  public:
    Magicstone_8() {}
	void operator() (Character &model);
};

#endif // MAGICSTONE_8_H
