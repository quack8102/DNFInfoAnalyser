#ifndef CLASS_32_H
#define CLASS_32_H

#include "equipment.h"

class Class_32 : public Equipment { // 伊斯塔战灵
public:
	Class_32(){}
	void operator() (Character &model);
};

#endif // CLASS_32_H
