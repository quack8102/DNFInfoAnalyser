#ifndef SHOES_14_H
#define SHOES_14_H

#include "equipment.h"

class Shoes_14 : public Equipment { // 交织烈日之风 Shoes: 4
  public:
    Shoes_14() {}
	void operator() (Character &model);
};

#endif // SHOES_14_H
