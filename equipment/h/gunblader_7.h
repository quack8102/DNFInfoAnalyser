#ifndef GUNBLADER_7_H
#define GUNBLADER_7_H

#include "equipment.h"

class Gunblader_7 : public Equipment { // 暗黑圣战之溯回：小太刀 Gunblader: 5
  public:
    Gunblader_7() {}
	void operator() (Character &model);
};

#endif // GUNBLADER_7_H
