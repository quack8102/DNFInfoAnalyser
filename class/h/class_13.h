#ifndef CLASS_13_H
#define CLASS_13_H

#include "equipment.h"

class Class_13 : public Equipment { // 归元·气功师
public:
	Class_13(){}
	void operator() (Character &model);
};

#endif // CLASS_13_H
