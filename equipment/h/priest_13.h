#ifndef PRIEST_13_H
#define PRIEST_13_H

#include "equipment.h"

class Priest_13 : public Equipment { // 暗战终结者 Priest: 5
  public:
    Priest_13() {}
	void operator() (Character &model);
};

#endif // PRIEST_13_H
