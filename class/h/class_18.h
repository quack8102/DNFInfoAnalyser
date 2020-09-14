#ifndef CLASS_18_H
#define CLASS_18_H

#include "equipment.h"

class Class_18 : public Equipment { // 重霄·枪炮师
public:
	Class_18(){}
	void operator() (Character &model);
};

#endif // CLASS_18_H
