#ifndef BELT_7_H
#define BELT_7_H

#include "equipment.h"

class Belt_7 : public Equipment { // 炙炎：山竹 Belt: 3
  public:
    Belt_7() {}
	void operator() (Character &model);
};

#endif // BELT_7_H
