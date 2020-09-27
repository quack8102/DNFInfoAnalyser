#ifndef PRIEST_29_H
#define PRIEST_29_H

#include "equipment.h"

class Priest_29 : public Equipment { // 飘零之花战斧
public:
	Priest_29(){}
	void operator() (Character &model);
};

#endif // PRIEST_29_H
