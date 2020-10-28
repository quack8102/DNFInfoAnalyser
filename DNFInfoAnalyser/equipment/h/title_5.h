#ifndef TITLE_5_H
#define TITLE_5_H

#include "equipment.h"

class Title_5 : public Equipment { // 最强战王 Title: 6
  public:
    Title_5() {}
	void operator() (Character &model);
};

#endif // TITLE_5_H
