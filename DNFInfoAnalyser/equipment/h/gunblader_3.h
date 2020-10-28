#ifndef GUNBLADER_3_H
#define GUNBLADER_3_H

#include "equipment.h"

class Gunblader_3 : public Equipment { // 金刚密藏刀 Gunblader: 5
  public:
    Gunblader_3() {}
	void operator() (Character &model);
};

#endif // GUNBLADER_3_H
