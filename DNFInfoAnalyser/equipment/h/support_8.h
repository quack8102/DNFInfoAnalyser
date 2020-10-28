#ifndef SUPPORT_8_H
#define SUPPORT_8_H

#include "equipment.h"

class Support_8 : public Equipment { // 腐蚀之黑色面具 Support: 9
  public:
    Support_8() {}
	void operator() (Character &model);
};

#endif // SUPPORT_8_H
