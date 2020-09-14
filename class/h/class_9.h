#ifndef CLASS_9_H
#define CLASS_9_H

#include "equipment.h"

class Class_9 : public Equipment { // 归元·气功师
public:
	Class_9(){}
	void operator() (Character &model);
};

#endif // CLASS_9_H
