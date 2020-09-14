#ifndef CLASS_14_H
#define CLASS_14_H

#include "equipment.h"

class Class_14 : public Equipment { // 归元·散打
public:
	Class_14(){}
	void operator() (Character &model);
};

#endif // CLASS_14_H
