#ifndef SUPPORT_5_H
#define SUPPORT_5_H

#include "equipment.h"

class Support_5 : public Equipment { // 引路者的旅行书 Support: 9
  public:
    Support_5() {}
	void operator() (Character &model);
};

#endif // SUPPORT_5_H
