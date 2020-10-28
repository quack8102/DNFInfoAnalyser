#ifndef CLASS_26_H
#define CLASS_26_H

#include "equipment.h"

class Class_26 : public Equipment { // 刹那永恒
public:
	Class_26(){}
	void operator() (Character &model);
};

#endif // CLASS_26_H
