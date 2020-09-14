#ifndef TITLE_3_H
#define TITLE_3_H

#include "equipment.h"

class Title_3 : public Equipment { // 桃园结义[义] Title: 6
  public:
    Title_3() {}
	void operator() (Character &model);
};

#endif // TITLE_3_H
