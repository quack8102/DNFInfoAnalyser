#ifndef BRACELET_9_H
#define BRACELET_9_H

#include "equipment.h"

class Bracelet_9 : public Equipment { // 拥抱晨曦之温暖 Bracelet: 7
  public:
    Bracelet_9() {}
	void operator() (Character &model);
};

#endif // BRACELET_9_H
