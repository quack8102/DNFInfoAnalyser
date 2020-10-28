#ifndef TITLE_7_H
#define TITLE_7_H

#include "equipment.h"

class Title_7 : public Equipment { // 最强战神 Title: 6
  public:
    Title_7() {}
	void operator() (Character &model);
};

#endif // TITLE_7_H
