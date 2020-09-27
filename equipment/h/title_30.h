#ifndef TITLE_30_H
#define TITLE_30_H

#include "equipment.h"

class Title_30 : public Equipment { // 安徒恩的炎魔之魂
public:
	Title_30(){}
	void operator() (Character &model);
};

#endif // TITLE_30_H
