#ifndef PANTS_14_H
#define PANTS_14_H

#include "equipment.h"

class Pants_14 : public Equipment { // 蚕食新绿之息 Pants: 2
  public:
    Pants_14() {}
	void operator() (Character &model);
};

#endif // PANTS_14_H
