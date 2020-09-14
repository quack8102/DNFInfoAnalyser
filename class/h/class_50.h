#ifndef CLASS_50_H
#define CLASS_50_H

#include "equipment.h"

class Class_50 : public Equipment { // 龙神
public:
	Class_50(){}
	void operator() (Character &model);
};

#endif // CLASS_50_H
