#ifndef GUNBLADER_5_H
#define GUNBLADER_5_H

#include "equipment.h"

class Gunblader_5 : public Equipment { // 夜语黑瞳小太刀 Gunblader: 5
  public:
    Gunblader_5() {}
	void operator() (Character &model);
};

#endif // GUNBLADER_5_H
