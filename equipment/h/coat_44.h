#ifndef COAT_44_H
#define COAT_44_H

#include "equipment.h"

class Coat_44 : public Equipment { // 最佳球手的暴走战衣 Coat: 1
  public:
    Coat_44() {}
	void operator() (Character &model);
};

#endif // COAT_44_H
