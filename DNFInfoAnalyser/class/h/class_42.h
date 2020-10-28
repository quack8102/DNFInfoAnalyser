#ifndef CLASS_42_H
#define CLASS_42_H

#include "equipment.h"

class Class_42 : public Equipment { // 救世主
public:
	Class_42(){}
	void operator() (Character &model);
};

#endif // CLASS_42_H
