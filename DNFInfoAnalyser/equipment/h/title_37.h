#ifndef TITLE_37_H
#define TITLE_37_H

#include "equipment.h"

class Title_37 : public Equipment { // 穿越星空的祈愿
public:
	Title_37(){}
	void operator() (Character &model);
};

#endif // TITLE_37_H
