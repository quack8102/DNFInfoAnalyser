#ifndef PANTS_18_H
#define PANTS_18_H

#include "equipment.h"

class Pants_18 : public Equipment { // 疯狂之如影随形 Pants: 2
  public:
    Pants_18() {}
	void operator() (Character &model);
};

#endif // PANTS_18_H
