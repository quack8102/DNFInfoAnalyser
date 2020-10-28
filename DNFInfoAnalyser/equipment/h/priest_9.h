#ifndef PRIEST_9_H
#define PRIEST_9_H

#include "equipment.h"

class Priest_9 : public Equipment { // 古代神兽的记忆 Priest: 5
  public:
    Priest_9() {}
	void operator() (Character &model);
};

#endif // PRIEST_9_H
