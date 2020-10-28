#ifndef BRACELET_21_H
#define BRACELET_21_H

#include "equipment.h"

class Bracelet_21 : public Equipment { // 雪浪风尘 Bracelet: 7
  public:
    Bracelet_21() {}
	void operator() (Character &model);
};

#endif // BRACELET_21_H
