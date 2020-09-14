#ifndef TITLE_25_H
#define TITLE_25_H

#include "equipment.h"

class Title_25 : public Equipment { // 万灵之尊 Title: 6
  public:
    Title_25() {}
	void operator() (Character &model);
};

#endif // TITLE_25_H
