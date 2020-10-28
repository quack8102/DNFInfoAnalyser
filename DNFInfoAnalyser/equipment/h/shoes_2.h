#ifndef SHOES_2_H
#define SHOES_2_H

#include "equipment.h"

class Shoes_2 : public Equipment { // 激烈欢动踢踏 Shoes: 4
  public:
    Shoes_2() {}
	void operator() (Character &model);
};

#endif // SHOES_2_H
