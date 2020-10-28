#ifndef TITLE_28_H
#define TITLE_28_H

#include "equipment.h"

class Title_28 : public Equipment { // 伊希斯的天空
public:
	Title_28(){}
	void operator() (Character &model);
};

#endif // TITLE_28_H
