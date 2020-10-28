#ifndef BELT_24_H
#define BELT_24_H

#include "equipment.h"

class Belt_24 : public Equipment { // 无我之轮回
public:
	Belt_24(){}
	void operator() (Character &model);
};

#endif // BELT_24_H
