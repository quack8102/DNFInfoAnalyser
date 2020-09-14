#ifndef SET_8_H
#define SET_8_H

#include "equipment.h"

class Set_8 : public Equipment { // 炙炎之盛宴
  public:
    Set_8() {}
	void operator() (Character &model);
};

#endif // SET_8_H
