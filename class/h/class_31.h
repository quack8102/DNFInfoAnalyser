#ifndef CLASS_31_H
#define CLASS_31_H

#include "equipment.h"

class Class_31 : public Equipment { // 月蚀
public:
	Class_31(){}
	void operator() (Character &model);
};

#endif // CLASS_31_H
