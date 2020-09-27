#ifndef SUPPORT_17_H
#define SUPPORT_17_H

#include "equipment.h"

class Support_17 : public Equipment { // 幻影：守门人的黑色面具
public:
	Support_17(){}
	void operator() (Character &model);
};

#endif // SUPPORT_17_H
