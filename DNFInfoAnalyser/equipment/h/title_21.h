#ifndef TITLE_21_H
#define TITLE_21_H

#include "equipment.h"

class Title_21 : public Equipment { // 白白海豚 Title: 6
  public:
    Title_21() {}
	void operator() (Character &model);
};

#endif // TITLE_21_H
