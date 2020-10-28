#ifndef NECK_0_H
#define NECK_0_H

#include "equipment.h"

class Neck_0 : public Equipment { // 大祭司的星祈披肩 Neck: 0
  public:
    Neck_0() {}
	void operator() (Character &model);
};

#endif // NECK_0_H
