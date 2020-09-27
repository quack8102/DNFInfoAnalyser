#ifndef SUPPORT_15_H
#define SUPPORT_15_H

#include "equipment.h"

class Support_15 : public Equipment { // 幻影：暗杀者的黑色剑鞘
public:
	Support_15(){}
	void operator() (Character &model);
};

#endif // SUPPORT_15_H
