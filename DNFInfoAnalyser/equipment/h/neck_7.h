#ifndef NECK_7_H
#define NECK_7_H

#include "equipment.h"

class Neck_7 : public Equipment { // 炙炎：榴莲 Neck: 0
  public:
    Neck_7() {}
	void operator() (Character &model);
};

#endif // NECK_7_H
