#ifndef DEMONICLANCER_12_H
#define DEMONICLANCER_12_H

#include "equipment.h"

class Demoniclancer_12 : public Equipment { // 暗黑圣战之溯回：光枪 Demoniclancer: 5
  public:
    Demoniclancer_12() {}
	void operator() (Character &model);
};

#endif // DEMONICLANCER_12_H
