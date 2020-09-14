#ifndef PRIEST_19_H
#define PRIEST_19_H

#include "equipment.h"

class Priest_19 : public Equipment { // 异教主的审判 Priest: 5
  public:
    Priest_19() {}
	void operator() (Character &model);
};

#endif // PRIEST_19_H
