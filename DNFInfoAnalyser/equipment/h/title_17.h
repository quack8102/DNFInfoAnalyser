#ifndef TITLE_17_H
#define TITLE_17_H

#include "equipment.h"

class Title_17 : public Equipment { // 使徒降临 Title: 6
  public:
    Title_17() {}
	void operator() (Character &model);
};

#endif // TITLE_17_H
