#ifndef SHOES_0_H
#define SHOES_0_H

#include "equipment.h"

class Shoes_0 : public Equipment { // 大祭司的星祈凉鞋 Shoes: 4
  public:
    Shoes_0() {}
	void operator() (Character &model);
};

#endif // SHOES_0_H
