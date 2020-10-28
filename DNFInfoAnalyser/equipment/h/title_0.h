#ifndef TITLE_0_H
#define TITLE_0_H

#include "equipment.h"

class Title_0 : public Equipment { // 魔女幻想 Title: 6
  public:
    Title_0() {}
	void operator() (Character &model);
};

#endif // TITLE_0_H
