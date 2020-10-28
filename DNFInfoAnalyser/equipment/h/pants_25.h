#ifndef PANTS_25_H
#define PANTS_25_H

#include "equipment.h"

class Pants_25 : public Equipment { // 千蛛碎影之蛛网护腿 Pants: 2
  public:
    Pants_25() {}
	void operator() (Character &model);
};

#endif // PANTS_25_H
