#ifndef CLASS_51_H
#define CLASS_51_H

#include "equipment.h"

class Class_51 : public Equipment { // 不灭战神
public:
	Class_51(){}
	void operator() (Character &model);
};

#endif // CLASS_51_H
