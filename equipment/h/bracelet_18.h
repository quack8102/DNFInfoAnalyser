#ifndef BRACELET_18_H
#define BRACELET_18_H

#include "equipment.h"

class Bracelet_18 : public Equipment { // 轮回：维度冲击臂环 Bracelet: 7
  public:
    Bracelet_18() {}
	void operator() (Character &model);
};

#endif // BRACELET_18_H
