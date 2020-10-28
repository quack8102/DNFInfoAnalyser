#ifndef CLASS_29_H
#define CLASS_29_H

#include "equipment.h"

class Class_29 : public Equipment { // 混沌行者
public:
	Class_29(){}
	void operator() (Character &model);
};

#endif // CLASS_29_H
