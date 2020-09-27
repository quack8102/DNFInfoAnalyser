#ifndef PRIEST_28_H
#define PRIEST_28_H

#include "equipment.h"

class Priest_28 : public Equipment { // 飘零之花镰刀
public:
	Priest_28(){}
	void operator() (Character &model);
};

#endif // PRIEST_28_H
