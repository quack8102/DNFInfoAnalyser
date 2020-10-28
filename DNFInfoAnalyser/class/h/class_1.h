#ifndef CLASS_1_H
#define CLASS_1_H

#include "equipment.h"

class Class_1 : public Equipment { // 极诣·鬼泣
public:
	Class_1(){}
	void operator() (Character &model);
};

#endif // CLASS_1_H
