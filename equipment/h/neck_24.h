#ifndef NECK_24_H
#define NECK_24_H

#include "equipment.h"

class Neck_24 : public Equipment { // 完美掌控 Neck: 0
  public:
    Neck_24() {}
	void operator() (Character &model);
};

#endif // NECK_24_H
