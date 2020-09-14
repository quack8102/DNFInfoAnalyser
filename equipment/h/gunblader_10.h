#ifndef GUNBLADER_10_H
#define GUNBLADER_10_H

#include "equipment.h"

class Gunblader_10 : public Equipment { // 夜语黑瞳重剑 Gunblader: 5
  public:
    Gunblader_10() {}
	void operator() (Character &model);
};

#endif // GUNBLADER_10_H
