#ifndef PRIEST_20_H
#define PRIEST_20_H

#include "equipment.h"

class Priest_20 : public Equipment { // 夜语黑瞳战斧 Priest: 5
  public:
    Priest_20() {}
	void operator() (Character &model);
};

#endif // PRIEST_20_H
