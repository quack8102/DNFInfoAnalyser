#ifndef THIEF_23_H
#define THIEF_23_H

#include "equipment.h"

class Thief_23 : public Equipment { // 飘零之花苦无
public:
	Thief_23(){}
	void operator() (Character &model);
};

#endif // THIEF_23_H
