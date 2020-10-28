#ifndef SET_38_H
#define SET_38_H

#include "equipment.h"

class Set_38 : public Equipment { // 暗之腐蚀
  public:
    Set_38() {}
	void operator() (Character &model);
};

#endif // SET_38_H
