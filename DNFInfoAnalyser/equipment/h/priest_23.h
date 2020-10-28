#ifndef PRIEST_23_H
#define PRIEST_23_H

#include "equipment.h"

class Priest_23 : public Equipment { // 弗卡奴斯的第二个痕迹 Priest: 5
  public:
    Priest_23() {}
	void operator() (Character &model);
};

#endif // PRIEST_23_H
