#ifndef GUNBLADER_1_H
#define GUNBLADER_1_H

#include "equipment.h"

class Gunblader_1 : public Equipment { // 界·夜语黑瞳长刀 Gunblader: 5
  public:
    Gunblader_1() {}
	void operator() (Character &model);
};

#endif // GUNBLADER_1_H
