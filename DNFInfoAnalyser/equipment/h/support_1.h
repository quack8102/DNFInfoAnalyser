#ifndef SUPPORT_1_H
#define SUPPORT_1_H

#include "equipment.h"

class Support_1 : public Equipment { // 高贵之天 Support: 9
  public:
    Support_1() {}
	void operator() (Character &model);
};

#endif // SUPPORT_1_H
