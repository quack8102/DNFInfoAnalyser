#ifndef THIEF_19_H
#define THIEF_19_H

#include "equipment.h"

class Thief_19 : public Equipment { // 天幕道火扇 Thief: 5
  public:
    Thief_19() {}
	void operator() (Character &model);
};

#endif // THIEF_19_H
