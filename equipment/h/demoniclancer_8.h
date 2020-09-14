#ifndef DEMONICLANCER_8_H
#define DEMONICLANCER_8_H

#include "equipment.h"

class Demoniclancer_8 : public Equipment { // 万夫之勇 Demoniclancer: 5
  public:
    Demoniclancer_8() {}
	void operator() (Character &model);
};

#endif // DEMONICLANCER_8_H
