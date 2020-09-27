#ifndef PRIEST_26_H
#define PRIEST_26_H

#include "equipment.h"

class Priest_26 : public Equipment { // 飘零之花念珠
public:
	Priest_26(){}
	void operator() (Character &model);
};

#endif // PRIEST_26_H
