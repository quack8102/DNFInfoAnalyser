#ifndef GUNBLADER_22_H
#define GUNBLADER_22_H

#include "equipment.h"

class Gunblader_22 : public Equipment { // 飘零之花重剑
public:
	Gunblader_22(){}
	void operator() (Character &model);
};

#endif // GUNBLADER_22_H
