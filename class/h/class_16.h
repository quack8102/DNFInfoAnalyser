#ifndef CLASS_16_H
#define CLASS_16_H

#include "equipment.h"

class Class_16 : public Equipment { // 归元·柔道家
public:
	Class_16(){}
	void operator() (Character &model);
};

#endif // CLASS_16_H
