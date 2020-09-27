#ifndef TITLE_27_H
#define TITLE_27_H

#include "equipment.h"

class Title_27 : public Equipment { // 安徒恩的烈焰
public:
	Title_27(){}
	void operator() (Character &model);
};

#endif // TITLE_27_H
