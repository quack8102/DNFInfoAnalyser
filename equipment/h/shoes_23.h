#ifndef SHOES_23_H
#define SHOES_23_H

#include "equipment.h"

class Shoes_23 : public Equipment { // 最佳球手的逆袭跑鞋 Shoes: 4
  public:
    Shoes_23() {}
	void operator() (Character &model);
};

#endif // SHOES_23_H
