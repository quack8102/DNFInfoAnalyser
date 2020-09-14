#ifndef GUNBLADER_16_H
#define GUNBLADER_16_H

#include "equipment.h"

class Gunblader_16 : public Equipment { // 界·夜语黑瞳源力剑 Gunblader: 5
  public:
    Gunblader_16() {}
	void operator() (Character &model);
};

#endif // GUNBLADER_16_H
