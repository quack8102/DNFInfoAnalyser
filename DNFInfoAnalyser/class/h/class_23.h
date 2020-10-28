#ifndef CLASS_23_H
#define CLASS_23_H

#include "equipment.h"

class Class_23 : public Equipment { // 机械之灵
public:
	Class_23(){}
	void operator() (Character &model);
};

#endif // CLASS_23_H
