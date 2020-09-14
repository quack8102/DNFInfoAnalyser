#ifndef GUNBLADER_13_H
#define GUNBLADER_13_H

#include "equipment.h"

class Gunblader_13 : public Equipment { // 聚能擎天剑 Gunblader: 5
  public:
    Gunblader_13() {}
	void operator() (Character &model);
};

#endif // GUNBLADER_13_H
