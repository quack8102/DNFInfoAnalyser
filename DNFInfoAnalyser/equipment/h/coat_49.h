#ifndef COAT_49_H
#define COAT_49_H

#include "equipment.h"

class Coat_49 : public Equipment { // 无念之仪服
public:
	Coat_49(){}
	void operator() (Character &model);
};

#endif // COAT_49_H
