#ifndef CLASS_15_H
#define CLASS_15_H

#include "equipment.h"

class Class_15 : public Equipment { // 归元·街霸
public:
	Class_15(){}
	void operator() (Character &model);
};

#endif // CLASS_15_H
