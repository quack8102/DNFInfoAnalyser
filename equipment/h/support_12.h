#ifndef SUPPORT_12_H
#define SUPPORT_12_H

#include "equipment.h"

class Support_12 : public Equipment { // 禁断契约书 Support: 9
  public:
    Support_12() {}
	void operator() (Character &model);
};

#endif // SUPPORT_12_H
