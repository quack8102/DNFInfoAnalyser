#ifndef CLASS_4_H
#define CLASS_4_H

#include "equipment.h"

class Class_4 : public Equipment { // 极诣·剑影
public:
	Class_4(){}
	void operator() (Character &model);
};

#endif // CLASS_4_H
