#ifndef SUPPORT_2_H
#define SUPPORT_2_H

#include "equipment.h"

class Support_2 : public Equipment { // 末日之刻 Support: 9
  public:
    Support_2() {}
	void operator() (Character &model);
};

#endif // SUPPORT_2_H
