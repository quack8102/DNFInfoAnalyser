#ifndef COAT_10_H
#define COAT_10_H

#include "equipment.h"

class Coat_10 : public Equipment { // 天堂之翼 Coat: 1
  public:
    Coat_10() {}
	void operator() (Character &model);
};

#endif // COAT_10_H
