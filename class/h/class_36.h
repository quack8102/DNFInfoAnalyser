#ifndef CLASS_36_H
#define CLASS_36_H

#include "equipment.h"

class Class_36 : public Equipment { // 正义仲裁者
public:
	Class_36(){}
	void operator() (Character &model);
};

#endif // CLASS_36_H
