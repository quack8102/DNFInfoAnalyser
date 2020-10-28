#ifndef THIEF_9_H
#define THIEF_9_H

#include "equipment.h"

class Thief_9 : public Equipment { // 血色舞会 Thief: 5
  public:
    Thief_9() {}
	void operator() (Character &model);
};

#endif // THIEF_9_H
