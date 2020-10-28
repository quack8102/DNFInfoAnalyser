#ifndef TITLE_12_H
#define TITLE_12_H

#include "equipment.h"

class Title_12 : public Equipment { // 天选之人 Title: 6
  public:
    Title_12() {}
	void operator() (Character &model);
};

#endif // TITLE_12_H
