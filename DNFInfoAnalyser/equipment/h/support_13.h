#ifndef SUPPORT_13_H
#define SUPPORT_13_H

#include "equipment.h"

class Support_13 : public Equipment { // 最佳球手之球 Support: 9
  public:
    Support_13() {}
	void operator() (Character &model);
};

#endif // SUPPORT_13_H
