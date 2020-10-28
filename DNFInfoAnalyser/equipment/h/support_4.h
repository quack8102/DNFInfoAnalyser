#ifndef SUPPORT_4_H
#define SUPPORT_4_H

#include "equipment.h"

class Support_4 : public Equipment { // 暗黑术士亲笔古书 Support: 9
  public:
    Support_4() {}
	void operator() (Character &model);
};

#endif // SUPPORT_4_H
