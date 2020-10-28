#ifndef SUPPORT_3_H
#define SUPPORT_3_H

#include "equipment.h"

class Support_3 : public Equipment { // 能量回流控制者 Support: 9
  public:
    Support_3() {}
	void operator() (Character &model);
};

#endif // SUPPORT_3_H
