#ifndef CLASS_10_H
#define CLASS_10_H

#include "equipment.h"

class Class_10 : public Equipment { // 归元·散打
public:
	Class_10(){}
	void operator() (Character &model);
};

#endif // CLASS_10_H
