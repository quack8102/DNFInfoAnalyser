#ifndef SUPPORT_10_H
#define SUPPORT_10_H

#include "equipment.h"

class Support_10 : public Equipment { // 青面修罗的面具 Support: 9
  public:
    Support_10() {}
	void operator() (Character &model);
};

#endif // SUPPORT_10_H
