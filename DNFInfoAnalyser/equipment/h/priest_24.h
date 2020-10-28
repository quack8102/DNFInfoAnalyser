#ifndef PRIEST_24_H
#define PRIEST_24_H

#include "equipment.h"

class Priest_24 : public Equipment { // 信念之重量 Priest: 5
  public:
    Priest_24() {}
	void operator() (Character &model);
};

#endif // PRIEST_24_H
