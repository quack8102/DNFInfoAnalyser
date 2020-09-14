#ifndef NECKLACE_6_H
#define NECKLACE_6_H

#include "equipment.h"

class Necklace_6 : public Equipment { // 悲痛者项链 Necklace: 8
  public:
    Necklace_6() {}
	void operator() (Character &model);
};

#endif // NECKLACE_6_H
