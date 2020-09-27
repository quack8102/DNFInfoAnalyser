#ifndef SUPPORT_18_H
#define SUPPORT_18_H

#include "equipment.h"

class Support_18 : public Equipment { // 幻影：洛多斯的黑色核心
public:
	Support_18(){}
	void operator() (Character &model);
};

#endif // SUPPORT_18_H
