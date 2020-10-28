#ifndef TITLE_13_H
#define TITLE_13_H

#include "equipment.h"

class Title_13 : public Equipment { // 神之试炼的奖赏 Title: 6
  public:
    Title_13() {}
	void operator() (Character &model);
};

#endif // TITLE_13_H
