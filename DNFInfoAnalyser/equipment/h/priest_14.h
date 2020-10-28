#ifndef PRIEST_14_H
#define PRIEST_14_H

#include "equipment.h"

class Priest_14 : public Equipment { // 拓荒者之路 Priest: 5
  public:
    Priest_14() {}
	void operator() (Character &model);
};

#endif // PRIEST_14_H
