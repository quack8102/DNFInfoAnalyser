#ifndef DEMONICLANCER_4_H
#define DEMONICLANCER_4_H

#include "equipment.h"

class Demoniclancer_4 : public Equipment { // 彪悍冲锋者 Demoniclancer: 5
  public:
    Demoniclancer_4() {}
	void operator() (Character &model);
};

#endif // DEMONICLANCER_4_H
