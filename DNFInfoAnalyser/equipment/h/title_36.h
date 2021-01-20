#ifndef TITLE_36_H
#define TITLE_36_H

#include "equipment.h"

class Title_36 : public Equipment { // 永恒战吼
public:
	Title_36(){}
	void operator() (Character &model);
};

#endif // TITLE_36_H
