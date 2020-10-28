#ifndef GUNBLADER_12_H
#define GUNBLADER_12_H

#include "equipment.h"

class Gunblader_12 : public Equipment { // 暗黑圣战之溯回：重剑 Gunblader: 5
  public:
    Gunblader_12() {}
	void operator() (Character &model);
};

#endif // GUNBLADER_12_H
