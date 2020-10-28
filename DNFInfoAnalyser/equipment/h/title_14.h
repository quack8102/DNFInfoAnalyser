#ifndef TITLE_14_H
#define TITLE_14_H

#include "equipment.h"

class Title_14 : public Equipment { // 秘境迷踪 Title: 6
  public:
    Title_14() {}
	void operator() (Character &model);
};

#endif // TITLE_14_H
