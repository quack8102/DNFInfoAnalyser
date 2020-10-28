#ifndef DEMONICLANCER_1_H
#define DEMONICLANCER_1_H

#include "equipment.h"

class Demoniclancer_1 : public Equipment { // 界·夜语黑瞳长枪 Demoniclancer: 5
  public:
    Demoniclancer_1() {}
	void operator() (Character &model);
};

#endif // DEMONICLANCER_1_H
