#ifndef TITLE_4_H
#define TITLE_4_H

#include "equipment.h"

class Title_4 : public Equipment { // 骑士王的荣耀 Title: 6
  public:
    Title_4() {}
	void operator() (Character &model);
};

#endif // TITLE_4_H
