#ifndef GUNBLADER_0_H
#define GUNBLADER_0_H

#include "equipment.h"

class Gunblader_0 : public Equipment { // 夜语黑瞳长刀 Gunblader: 5
  public:
    Gunblader_0() {}
	void operator() (Character &model);
};

#endif // GUNBLADER_0_H
