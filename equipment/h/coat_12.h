#ifndef COAT_12_H
#define COAT_12_H

#include "equipment.h"

class Coat_12 : public Equipment { // 英明循环之生命 Coat: 1
  public:
    Coat_12() {}
	void operator() (Character &model);
};

#endif // COAT_12_H
