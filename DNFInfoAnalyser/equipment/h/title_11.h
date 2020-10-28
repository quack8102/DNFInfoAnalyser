#ifndef TITLE_11_H
#define TITLE_11_H

#include "equipment.h"

class Title_11 : public Equipment { // 兽人守护神 Title: 6
  public:
    Title_11() {}
	void operator() (Character &model);
};

#endif // TITLE_11_H
