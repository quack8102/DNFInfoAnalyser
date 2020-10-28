#ifndef SHOES_28_H
#define SHOES_28_H

#include "equipment.h"

class Shoes_28 : public Equipment { // 无言之罪恶
public:
	Shoes_28(){}
	void operator() (Character &model);
};

#endif // SHOES_28_H
