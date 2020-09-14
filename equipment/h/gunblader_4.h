#ifndef GUNBLADER_4_H
#define GUNBLADER_4_H

#include "equipment.h"

class Gunblader_4 : public Equipment { // 夜天刀 Gunblader: 5
  public:
    Gunblader_4() {}
	void operator() (Character &model);
};

#endif // GUNBLADER_4_H
