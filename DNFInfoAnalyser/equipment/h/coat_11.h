#ifndef COAT_11_H
#define COAT_11_H

#include "equipment.h"

class Coat_11 : public Equipment { // 千链万化战甲 Coat: 1
  public:
    Coat_11() {}
	void operator() (Character &model);
};

#endif // COAT_11_H
