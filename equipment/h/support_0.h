#ifndef SUPPORT_0_H
#define SUPPORT_0_H

#include "equipment.h"

class Support_0 : public Equipment { // 军神的遗书 Support: 9
  public:
    Support_0() {}
	void operator() (Character &model);
};

#endif // SUPPORT_0_H
