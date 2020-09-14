#ifndef PRIEST_21_H
#define PRIEST_21_H

#include "equipment.h"

class Priest_21 : public Equipment { // 界·夜语黑瞳战斧 Priest: 5
  public:
    Priest_21() {}
	void operator() (Character &model);
};

#endif // PRIEST_21_H
