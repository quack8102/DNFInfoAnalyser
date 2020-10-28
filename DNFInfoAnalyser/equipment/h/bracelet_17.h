#ifndef BRACELET_17_H
#define BRACELET_17_H

#include "equipment.h"

class Bracelet_17 : public Equipment { // 时空：维度冲击臂环 Bracelet: 7
  public:
    Bracelet_17() {}
	void operator() (Character &model);
};

#endif // BRACELET_17_H
