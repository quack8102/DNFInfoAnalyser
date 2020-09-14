#ifndef CLASS_11_H
#define CLASS_11_H

#include "equipment.h"

class Class_11 : public Equipment { // 归元·街霸
public:
	Class_11(){}
	void operator() (Character &model);
};

#endif // CLASS_11_H
