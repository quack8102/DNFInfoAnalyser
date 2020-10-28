#ifndef CLASS_59_H
#define CLASS_59_H

#include "equipment.h"

class Class_59 : public Equipment { // 缔造者
public:
	Class_59(){}
	void operator() (Character &model);
};

#endif // CLASS_59_H
