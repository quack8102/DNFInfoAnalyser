#ifndef PANTS_7_H
#define PANTS_7_H

#include "equipment.h"

class Pants_7 : public Equipment { // 炙炎：荔枝 Pants: 2
  public:
    Pants_7() {}
	void operator() (Character &model);
};

#endif // PANTS_7_H
