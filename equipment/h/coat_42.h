#ifndef COAT_42_H
#define COAT_42_H

#include "equipment.h"

class Coat_42 : public Equipment { // 暗魅之影上衣 Coat: 1
  public:
    Coat_42() {}
	void operator() (Character &model);
};

#endif // COAT_42_H
