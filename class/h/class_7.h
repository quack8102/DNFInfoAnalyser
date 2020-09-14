#ifndef CLASS_7_H
#define CLASS_7_H

#include "equipment.h"

class Class_7 : public Equipment { // 极诣·契魔者
public:
	Class_7(){}
	void operator() (Character &model);
};

#endif // CLASS_7_H
