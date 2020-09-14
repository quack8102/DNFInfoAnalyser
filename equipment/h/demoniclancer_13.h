#ifndef DEMONICLANCER_13_H
#define DEMONICLANCER_13_H

#include "equipment.h"

class Demoniclancer_13 : public Equipment { // 千芒闪爆枪 Demoniclancer: 5
  public:
    Demoniclancer_13() {}
	void operator() (Character &model);
};

#endif // DEMONICLANCER_13_H
