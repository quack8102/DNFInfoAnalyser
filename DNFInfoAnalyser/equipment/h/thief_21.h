#ifndef THIEF_21_H
#define THIEF_21_H

#include "equipment.h"

class Thief_21 : public Equipment { // 飘零之花双剑
public:
	Thief_21(){}
	void operator() (Character &model);
};

#endif // THIEF_21_H
