#ifndef TITLE_18_H
#define TITLE_18_H

#include "equipment.h"

class Title_18 : public Equipment { // 伟大的意志 Title: 6
  public:
    Title_18() {}
	void operator() (Character &model);
};

#endif // TITLE_18_H
