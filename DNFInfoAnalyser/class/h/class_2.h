#ifndef CLASS_2_H
#define CLASS_2_H

#include "equipment.h"

class Class_2 : public Equipment { // 极诣·狂战士
public:
	Class_2(){}
	void operator() (Character &model);
};

#endif // CLASS_2_H
