#ifndef TITLE_1_H
#define TITLE_1_H

#include "equipment.h"

class Title_1 : public Equipment { // 圣殿之巅 Title: 6
  public:
    Title_1() {}
	void operator() (Character &model);
};

#endif // TITLE_1_H
