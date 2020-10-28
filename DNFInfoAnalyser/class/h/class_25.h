#ifndef CLASS_25_H
#define CLASS_25_H

#include "equipment.h"

class Class_25 : public Equipment { // 湮灭之瞳
public:
	Class_25(){}
	void operator() (Character &model);
};

#endif // CLASS_25_H
