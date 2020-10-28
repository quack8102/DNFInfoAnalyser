#ifndef PRIEST_11_H
#define PRIEST_11_H

#include "equipment.h"

class Priest_11 : public Equipment { // 界·夜语黑瞳图腾 Priest: 5
  public:
    Priest_11() {}
	void operator() (Character &model);
};

#endif // PRIEST_11_H
