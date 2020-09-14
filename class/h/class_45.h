#ifndef CLASS_45_H
#define CLASS_45_H

#include "equipment.h"

class Class_45 : public Equipment { // 不知火
public:
	Class_45(){}
	void operator() (Character &model);
};

#endif // CLASS_45_H
