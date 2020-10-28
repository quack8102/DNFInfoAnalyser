#ifndef GUNBLADER_14_H
#define GUNBLADER_14_H

#include "equipment.h"

class Gunblader_14 : public Equipment { // 爆烈红焰 Gunblader: 5
  public:
    Gunblader_14() {}
	void operator() (Character &model);
};

#endif // GUNBLADER_14_H
