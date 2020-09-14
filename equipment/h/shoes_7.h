#ifndef SHOES_7_H
#define SHOES_7_H

#include "equipment.h"

class Shoes_7 : public Equipment { // 炙炎：木瓜 Shoes: 4
  public:
    Shoes_7() {}
	void operator() (Character &model);
};

#endif // SHOES_7_H
