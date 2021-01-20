#ifndef TITLE_34_H
#define TITLE_34_H

#include "equipment.h"

class Title_34 : public Equipment { // 永恒追猎
public:
	Title_34(){}
	void operator() (Character &model);
};

#endif // TITLE_34_H
