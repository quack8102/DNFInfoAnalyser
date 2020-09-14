#ifndef PANTS_19_H
#define PANTS_19_H

#include "equipment.h"

class Pants_19 : public Equipment { // 黑暗幽灵紫杉护腿 Pants: 2
  public:
    Pants_19() {}
	void operator() (Character &model);
};

#endif // PANTS_19_H
