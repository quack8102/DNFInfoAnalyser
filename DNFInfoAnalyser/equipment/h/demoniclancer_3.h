#ifndef DEMONICLANCER_3_H
#define DEMONICLANCER_3_H

#include "equipment.h"

class Demoniclancer_3 : public Equipment { // 幻影狂欢长枪 Demoniclancer: 5
  public:
    Demoniclancer_3() {}
	void operator() (Character &model);
};

#endif // DEMONICLANCER_3_H
