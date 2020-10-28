#ifndef CLASS_28_H
#define CLASS_28_H

#include "equipment.h"

class Class_28 : public Equipment { // 风神
public:
	Class_28(){}
	void operator() (Character &model);
};

#endif // CLASS_28_H
