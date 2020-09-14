#ifndef PANTS_4_H
#define PANTS_4_H

#include "equipment.h"

class Pants_4 : public Equipment { // 首席执行官裁决短裤 Pants: 2
  public:
    Pants_4() {}
	void operator() (Character &model);
};

#endif // PANTS_4_H
