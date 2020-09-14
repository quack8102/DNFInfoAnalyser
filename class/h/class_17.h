#ifndef CLASS_17_H
#define CLASS_17_H

#include "equipment.h"

class Class_17 : public Equipment { // 重霄·漫游枪手
public:
	Class_17(){}
	void operator() (Character &model);
};

#endif // CLASS_17_H
