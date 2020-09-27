#ifndef TITLE_31_H
#define TITLE_31_H

#include "equipment.h"

class Title_31 : public Equipment { // 卢克的创生之灵
public:
	Title_31(){}
	void operator() (Character &model);
};

#endif // TITLE_31_H
