#ifndef TITLE_6_H
#define TITLE_6_H

#include "equipment.h"

class Title_6 : public Equipment { // 最强战皇 Title: 6
  public:
    Title_6() {}
	void operator() (Character &model);
};

#endif // TITLE_6_H
