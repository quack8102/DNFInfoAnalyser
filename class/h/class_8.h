#ifndef CLASS_8_H
#define CLASS_8_H

#include "equipment.h"

class Class_8 : public Equipment { // 极诣·流浪武士
public:
	Class_8(){}
	void operator() (Character &model);
};

#endif // CLASS_8_H
