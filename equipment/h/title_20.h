#ifndef TITLE_20_H
#define TITLE_20_H

#include "equipment.h"

class Title_20 : public Equipment { // 粉粉海豚 Title: 6
  public:
    Title_20() {}
	void operator() (Character &model);
};

#endif // TITLE_20_H
