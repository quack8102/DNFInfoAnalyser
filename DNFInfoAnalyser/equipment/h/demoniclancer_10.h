#ifndef DEMONICLANCER_10_H
#define DEMONICLANCER_10_H

#include "equipment.h"

class Demoniclancer_10 : public Equipment { // 夜雨黑瞳光枪 Demoniclancer: 5
  public:
    Demoniclancer_10() {}
	void operator() (Character &model);
};

#endif // DEMONICLANCER_10_H
