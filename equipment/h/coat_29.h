#ifndef COAT_29_H
#define COAT_29_H

#include "equipment.h"

class Coat_29 : public Equipment { // 妖精之姿 Coat: 1
  public:
    Coat_29() {}
	void operator() (Character &model);
};

#endif // COAT_29_H
