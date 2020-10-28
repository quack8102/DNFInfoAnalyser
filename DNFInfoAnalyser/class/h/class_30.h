#ifndef CLASS_30_H
#define CLASS_30_H

#include "equipment.h"

class Class_30 : public Equipment { // 元素圣灵
public:
	Class_30(){}
	void operator() (Character &model);
};

#endif // CLASS_30_H
