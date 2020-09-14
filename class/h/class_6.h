#ifndef CLASS_6_H
#define CLASS_6_H

#include "equipment.h"

class Class_6 : public Equipment { // 极诣·暗殿骑士
public:
	Class_6(){}
	void operator() (Character &model);
};

#endif // CLASS_6_H
