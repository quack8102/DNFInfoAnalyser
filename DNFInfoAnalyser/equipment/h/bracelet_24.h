#ifndef BRACELET_24_H
#define BRACELET_24_H

#include "equipment.h"

class Bracelet_24 : public Equipment { // 无言怒火
public:
	Bracelet_24(){}
	void operator() (Character &model);
};

#endif // BRACELET_24_H
