#ifndef TITLE_33_H
#define TITLE_33_H

#include "equipment.h"

class Title_33 : public Equipment { // 希洛克的无形之心
public:
	Title_33(){}
	void operator() (Character &model);
};

#endif // TITLE_33_H
