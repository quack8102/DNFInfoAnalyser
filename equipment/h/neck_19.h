#ifndef NECK_19_H
#define NECK_19_H

#include "equipment.h"

class Neck_19 : public Equipment { // 最佳球手的反击护具 Neck: 0
  public:
    Neck_19() {}
	void operator() (Character &model);
};

#endif // NECK_19_H
