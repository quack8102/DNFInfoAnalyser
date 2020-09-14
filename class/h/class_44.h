#ifndef CLASS_44_H
#define CLASS_44_H

#include "equipment.h"

class Class_44 : public Equipment { // 亡魂主宰
public:
	Class_44(){}
	void operator() (Character &model);
};

#endif // CLASS_44_H
