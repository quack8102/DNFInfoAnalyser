#ifndef TITLE_29_H
#define TITLE_29_H

#include "equipment.h"

class Title_29 : public Equipment { // 希洛克的悲鸣
public:
	Title_29(){}
	void operator() (Character &model);
};

#endif // TITLE_29_H
