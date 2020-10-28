#ifndef CLASS_53_H
#define CLASS_53_H

#include "equipment.h"

class Class_53 : public Equipment { // 屠戮之魂
public:
	Class_53(){}
	void operator() (Character &model);
};

#endif // CLASS_53_H
