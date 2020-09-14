#ifndef CLASS_21_H
#define CLASS_21_H

#include "equipment.h"

class Class_21 : public Equipment { // 绯红玫瑰
public:
	Class_21(){}
	void operator() (Character &model);
};

#endif // CLASS_21_H
