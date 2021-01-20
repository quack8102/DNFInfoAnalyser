#ifndef TITLE_35_H
#define TITLE_35_H

#include "equipment.h"

class Title_35 : public Equipment { // 永恒判罪
public:
	Title_35(){}
	void operator() (Character &model);
};

#endif // TITLE_35_H
