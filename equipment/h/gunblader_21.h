#ifndef GUNBLADER_21_H
#define GUNBLADER_21_H

#include "equipment.h"

class Gunblader_21 : public Equipment { // 飘零之花小太刀
public:
	Gunblader_21(){}
	void operator() (Character &model);
};

#endif // GUNBLADER_21_H
