#ifndef TITLE_9_H
#define TITLE_9_H

#include "equipment.h"

class Title_9 : public Equipment { // 龙之威仪 Title: 6
  public:
    Title_9() {}
	void operator() (Character &model);
};

#endif // TITLE_9_H
