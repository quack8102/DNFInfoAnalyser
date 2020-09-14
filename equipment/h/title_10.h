#ifndef TITLE_10_H
#define TITLE_10_H

#include "equipment.h"

class Title_10 : public Equipment { // 海洋霸主 Title: 6
  public:
    Title_10() {}
	void operator() (Character &model);
};

#endif // TITLE_10_H
