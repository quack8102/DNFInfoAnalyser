#ifndef TITLE_15_H
#define TITLE_15_H

#include "equipment.h"

class Title_15 : public Equipment { // 神选之英杰 Title: 6
  public:
    Title_15() {}
	void operator() (Character &model);
};

#endif // TITLE_15_H
