#ifndef CLASS_20_H
#define CLASS_20_H

#include "equipment.h"

class Class_20 : public Equipment { // 重霄·弹药专家
public:
	Class_20(){}
	void operator() (Character &model);
};

#endif // CLASS_20_H
