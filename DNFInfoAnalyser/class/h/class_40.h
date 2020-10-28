#ifndef CLASS_40_H
#define CLASS_40_H

#include "equipment.h"

class Class_40 : public Equipment { // 炎狱裁决者
public:
	Class_40(){}
	void operator() (Character &model);
};

#endif // CLASS_40_H
