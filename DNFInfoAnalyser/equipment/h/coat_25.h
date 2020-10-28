#ifndef COAT_25_H
#define COAT_25_H

#include "equipment.h"

class Coat_25 : public Equipment { // 燃烧烈焰之勇气 Coat: 1
  public:
    Coat_25() {}
	void operator() (Character &model);
};

#endif // COAT_25_H
