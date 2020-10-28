#ifndef GUNBLADER_17_H
#define GUNBLADER_17_H

#include "equipment.h"

class Gunblader_17 : public Equipment { // 暗黑圣战之溯回：源力剑 Gunblader: 5
  public:
    Gunblader_17() {}
	void operator() (Character &model);
};

#endif // GUNBLADER_17_H
