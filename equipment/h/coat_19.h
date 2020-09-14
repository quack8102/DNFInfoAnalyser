#ifndef COAT_19_H
#define COAT_19_H

#include "equipment.h"

class Coat_19 : public Equipment { // 大祭司的星祈礼袍 Coat: 1
  public:
    Coat_19() {}
	void operator() (Character &model);
};

#endif // COAT_19_H
