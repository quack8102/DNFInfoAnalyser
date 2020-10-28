#ifndef CLASS_22_H
#define CLASS_22_H

#include "equipment.h"

class Class_22 : public Equipment { // 风暴骑兵
public:
	Class_22(){}
	void operator() (Character &model);
};

#endif // CLASS_22_H
