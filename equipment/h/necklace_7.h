#ifndef NECKLACE_7_H
#define NECKLACE_7_H

#include "equipment.h"

class Necklace_7 : public Equipment { // 激狂之怒 Necklace: 8
  public:
    Necklace_7() {}
	void operator() (Character &model);
};

#endif // NECKLACE_7_H
