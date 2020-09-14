#ifndef GUNBLADER_18_H
#define GUNBLADER_18_H

#include "equipment.h"

class Gunblader_18 : public Equipment { // 远古御神战剑 Gunblader: 5
  public:
    Gunblader_18() {}
	void operator() (Character &model);
};

#endif // GUNBLADER_18_H
