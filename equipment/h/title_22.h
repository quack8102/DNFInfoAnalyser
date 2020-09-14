#ifndef TITLE_22_H
#define TITLE_22_H

#include "equipment.h"

class Title_22 : public Equipment { // 墨墨海豚 Title: 6
  public:
    Title_22() {}
	void operator() (Character &model);
};

#endif // TITLE_22_H
