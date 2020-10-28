#ifndef CLASS_3_H
#define CLASS_3_H

#include "equipment.h"

class Class_3 : public Equipment { // 极诣·阿修罗
public:
	Class_3(){}
	void operator() (Character &model);
};

#endif // CLASS_3_H
