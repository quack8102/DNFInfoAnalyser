#ifndef TITLE_16_H
#define TITLE_16_H

#include "equipment.h"

class Title_16 : public Equipment { // 超越极限者 Title: 6
  public:
    Title_16() {}
	void operator() (Character &model);
};

#endif // TITLE_16_H
