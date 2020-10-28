#ifndef BRACELET_3_H
#define BRACELET_3_H

#include "equipment.h"

class Bracelet_3 : public Equipment { // 至高之炎-伊弗利特 Bracelet: 7
  public:
    Bracelet_3() {}
	void operator() (Character &model);
};

#endif // BRACELET_3_H
