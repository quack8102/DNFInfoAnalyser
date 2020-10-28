#ifndef GUNBLADER_23_H
#define GUNBLADER_23_H

#include "equipment.h"

class Gunblader_23 : public Equipment { // 飘零之花源力剑
public:
	Gunblader_23(){}
	void operator() (Character &model);
};

#endif // GUNBLADER_23_H
