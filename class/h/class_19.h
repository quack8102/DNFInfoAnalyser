#ifndef CLASS_19_H
#define CLASS_19_H

#include "equipment.h"

class Class_19 : public Equipment { // 重霄·机械师
public:
	Class_19(){}
	void operator() (Character &model);
};

#endif // CLASS_19_H
