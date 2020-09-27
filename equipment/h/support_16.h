#ifndef SUPPORT_16_H
#define SUPPORT_16_H

#include "equipment.h"

class Support_16 : public Equipment { // 幻影：卢克西的黑色鬼神缚
public:
	Support_16(){}
	void operator() (Character &model);
};

#endif // SUPPORT_16_H
