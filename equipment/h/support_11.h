#ifndef SUPPORT_11_H
#define SUPPORT_11_H

#include "equipment.h"

class Support_11 : public Equipment { // 聚魔漩涡 Support: 9
  public:
    Support_11() {}
	void operator() (Character &model);
};

#endif // SUPPORT_11_H
