#ifndef SUPPORT_7_H
#define SUPPORT_7_H

#include "equipment.h"

class Support_7 : public Equipment { // 失控之怒 Support: 9
  public:
    Support_7() {}
	void operator() (Character &model);
};

#endif // SUPPORT_7_H
