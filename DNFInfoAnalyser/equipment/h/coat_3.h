#ifndef COAT_3_H
#define COAT_3_H

#include "equipment.h"

class Coat_3 : public Equipment { // 掌管生死之影夹克 Coat: 1
  public:
    Coat_3() {}
	void operator() (Character &model);
};

#endif // COAT_3_H
