#ifndef THIEF_18_H
#define THIEF_18_H

#include "equipment.h"

class Thief_18 : public Equipment { // 血腥红宝石之眼 Thief: 5
  public:
    Thief_18() {}
	void operator() (Character &model);
};

#endif // THIEF_18_H
