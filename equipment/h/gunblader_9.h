#ifndef GUNBLADER_9_H
#define GUNBLADER_9_H

#include "equipment.h"

class Gunblader_9 : public Equipment { // 冥焰黑暗之触 Gunblader: 5
  public:
    Gunblader_9() {}
	void operator() (Character &model);
};

#endif // GUNBLADER_9_H
