#ifndef PRIEST_10_H
#define PRIEST_10_H

#include "equipment.h"

class Priest_10 : public Equipment { // 夜语黑瞳图腾 Priest: 5
  public:
    Priest_10() {}
	void operator() (Character &model);
};

#endif // PRIEST_10_H
