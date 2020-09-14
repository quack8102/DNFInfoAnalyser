#ifndef PANTS_6_H
#define PANTS_6_H

#include "equipment.h"

class Pants_6 : public Equipment { // 肆虐狂风之意志 Pants: 2
  public:
    Pants_6() {}
	void operator() (Character &model);
};

#endif // PANTS_6_H
