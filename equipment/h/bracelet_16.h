#ifndef BRACELET_16_H
#define BRACELET_16_H

#include "equipment.h"

class Bracelet_16 : public Equipment { // 维度冲击臂环 Bracelet: 7
  public:
    Bracelet_16() {}
	void operator() (Character &model);
};

#endif // BRACELET_16_H
