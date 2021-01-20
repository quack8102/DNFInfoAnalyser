#ifndef SUPPORT_19_H
#define SUPPORT_19_H

#include "equipment.h"

class Support_19 : public Equipment { // 支配者王冠
public:
	Support_19(){}
	void operator() (Character &model);
};

#endif // SUPPORT_19_H
