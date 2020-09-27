#ifndef PANTS_30_H
#define PANTS_30_H

#include "equipment.h"

class Pants_30 : public Equipment { // 无形：暗杀者的灵魂残念
public:
	Pants_30(){}
	void operator() (Character &model);
};

#endif // PANTS_30_H
