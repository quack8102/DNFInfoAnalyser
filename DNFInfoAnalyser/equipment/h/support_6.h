#ifndef SUPPORT_6_H
#define SUPPORT_6_H

#include "equipment.h"

class Support_6 : public Equipment { // 悲情者遗物 Support: 9
  public:
    Support_6() {}
	void operator() (Character &model);
};

#endif // SUPPORT_6_H
