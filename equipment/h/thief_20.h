#ifndef THIEF_20_H
#define THIEF_20_H

#include "equipment.h"

class Thief_20 : public Equipment { // 飘零之花匕首
public:
	Thief_20(){}
	void operator() (Character &model);
};

#endif // THIEF_20_H
