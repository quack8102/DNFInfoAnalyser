#ifndef SHOES_6_H
#define SHOES_6_H

#include "equipment.h"

class Shoes_6 : public Equipment { // 寂静寒夜之忍耐 Shoes: 4
  public:
    Shoes_6() {}
	void operator() (Character &model);
};

#endif // SHOES_6_H
