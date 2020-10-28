#ifndef GUNNER_9_H
#define GUNNER_9_H

#include "equipment.h"

class Gunner_9 : public Equipment { // 雷霆怒啸手枪 Gunner: 5
  public:
    Gunner_9() {}
	void operator() (Character &model);
};

#endif // GUNNER_9_H
