#ifndef TITLE_2_H
#define TITLE_2_H

#include "equipment.h"

class Title_2 : public Equipment { // 三英雄[义] Title: 6
  public:
    Title_2() {}
	void operator() (Character &model);
};

#endif // TITLE_2_H
