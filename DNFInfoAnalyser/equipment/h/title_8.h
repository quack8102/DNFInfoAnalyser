#ifndef TITLE_8_H
#define TITLE_8_H

#include "equipment.h"

class Title_8 : public Equipment { // 龙之挑战 Title: 6
  public:
    Title_8() {}
	void operator() (Character &model);
};

#endif // TITLE_8_H
