#ifndef PANTS_8_H
#define PANTS_8_H

#include "equipment.h"

class Pants_8 : public Equipment { // 雷霆万钧护腿 Pants: 2
  public:
    Pants_8() {}
	void operator() (Character &model);
};

#endif // PANTS_8_H
