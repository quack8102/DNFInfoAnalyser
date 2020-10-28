#ifndef COAT_7_H
#define COAT_7_H

#include "equipment.h"

class Coat_7 : public Equipment { // 炙炎：霸王树 Coat: 1
  public:
    Coat_7() {}
	void operator() (Character &model);
};

#endif // COAT_7_H
