#ifndef PRIEST_25_H
#define PRIEST_25_H

#include "equipment.h"

class Priest_25 : public Equipment { // 飘零之花十字架
public:
	Priest_25(){}
	void operator() (Character &model);
};

#endif // PRIEST_25_H
