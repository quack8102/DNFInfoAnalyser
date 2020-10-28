#ifndef COAT_26_H
#define COAT_26_H

#include "equipment.h"

class Coat_26 : public Equipment { // 炙炎：火龙果 Coat: 1
  public:
    Coat_26() {}
	void operator() (Character &model);
};

#endif // COAT_26_H
