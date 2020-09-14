#ifndef DEMONICLANCER_2_H
#define DEMONICLANCER_2_H

#include "equipment.h"

class Demoniclancer_2 : public Equipment { // 暗黑圣战之溯回：长枪 Demoniclancer: 5
  public:
    Demoniclancer_2() {}
	void operator() (Character &model);
};

#endif // DEMONICLANCER_2_H
