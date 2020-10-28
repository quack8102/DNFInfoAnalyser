#ifndef GUNBLADER_2_H
#define GUNBLADER_2_H

#include "equipment.h"

class Gunblader_2 : public Equipment { // 暗黑圣战之溯回：长刀 Gunblader: 5
  public:
    Gunblader_2() {}
	void operator() (Character &model);
};

#endif // GUNBLADER_2_H
