#ifndef SUPPORT_9_H
#define SUPPORT_9_H

#include "equipment.h"

class Support_9 : public Equipment { // 循环：无尽的诞生 Support: 9
  public:
    Support_9() {}
	void operator() (Character &model);
};

#endif // SUPPORT_9_H
