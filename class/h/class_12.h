#ifndef CLASS_12_H
#define CLASS_12_H

#include "equipment.h"

class Class_12 : public Equipment { // 归元·柔道家
public:
	Class_12(){}
	void operator() (Character &model);
};

#endif // CLASS_12_H
