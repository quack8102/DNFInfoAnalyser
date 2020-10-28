#ifndef CLASS_38_H
#define CLASS_38_H

#include "equipment.h"

class Class_38 : public Equipment { // 永生者
public:
	Class_38(){}
	void operator() (Character &model);
};

#endif // CLASS_38_H
