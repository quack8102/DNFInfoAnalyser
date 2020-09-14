#ifndef SET_35_H
#define SET_35_H

#include "equipment.h"

class Set_35 : public Equipment { // 悲剧的残骸
  public:
    Set_35() {}
	void operator() (Character &model);
};

#endif // SET_35_H
