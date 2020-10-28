#ifndef THIEF_4_H
#define THIEF_4_H

#include "equipment.h"

class Thief_4 : public Equipment { // 暗杀团长的玉妆刀 Thief: 5
  public:
    Thief_4() {}
	void operator() (Character &model);
};

#endif // THIEF_4_H
