#ifndef DEMONICLANCER_0_H
#define DEMONICLANCER_0_H

#include "equipment.h"

class Demoniclancer_0 : public Equipment { // 夜语黑瞳长枪 Demoniclancer: 5
  public:
    Demoniclancer_0() {}
	void operator() (Character &model);
};

#endif // DEMONICLANCER_0_H
