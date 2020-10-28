#ifndef PRIEST_27_H
#define PRIEST_27_H

#include "equipment.h"

class Priest_27 : public Equipment { // 飘零之花图腾
public:
	Priest_27(){}
	void operator() (Character &model);
};

#endif // PRIEST_27_H
