#ifndef GUNBLADER_20_H
#define GUNBLADER_20_H

#include "equipment.h"

class Gunblader_20 : public Equipment { // 飘零之花长刀
public:
	Gunblader_20(){}
	void operator() (Character &model);
};

#endif // GUNBLADER_20_H
