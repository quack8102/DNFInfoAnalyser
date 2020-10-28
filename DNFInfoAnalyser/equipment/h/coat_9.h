#ifndef COAT_9_H
#define COAT_9_H

#include "equipment.h"

class Coat_9 : public Equipment { // 撒旦：愤怒之王 Coat: 1
  public:
    Coat_9() {}
	void operator() (Character &model);
};

#endif // COAT_9_H
