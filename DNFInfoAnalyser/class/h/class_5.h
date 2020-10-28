#ifndef CLASS_5_H
#define CLASS_5_H

#include "equipment.h"

class Class_5 : public Equipment { // 极诣·驭剑士
public:
	Class_5(){}
	void operator() (Character &model);
};

#endif // CLASS_5_H
