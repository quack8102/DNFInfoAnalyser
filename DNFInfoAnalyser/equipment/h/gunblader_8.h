#ifndef GUNBLADER_8_H
#define GUNBLADER_8_H

#include "equipment.h"

class Gunblader_8 : public Equipment { // 冰洁的红焰 Gunblader: 5
  public:
    Gunblader_8() {}
	void operator() (Character &model);
};

#endif // GUNBLADER_8_H
