#ifndef CLASS_60_H
#define CLASS_60_H

#include "equipment.h"

class Class_60 : public Equipment { // 黑暗武士
public:
	Class_60(){}
	void operator() (Character &model);
};

#endif // CLASS_60_H
