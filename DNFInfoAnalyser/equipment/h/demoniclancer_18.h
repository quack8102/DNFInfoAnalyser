#ifndef DEMONICLANCER_18_H
#define DEMONICLANCER_18_H

#include "equipment.h"

class Demoniclancer_18 : public Equipment { // 寂灭剧毒矛 Demoniclancer: 5
  public:
    Demoniclancer_18() {}
	void operator() (Character &model);
};

#endif // DEMONICLANCER_18_H
