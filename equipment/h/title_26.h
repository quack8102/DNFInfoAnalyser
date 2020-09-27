#ifndef TITLE_26_H
#define TITLE_26_H

#include "equipment.h"

class title_26 : public Equipment { // 卢克的创造
  public:
    title_26() {}
    void operator() (Character &model);
};

#endif // ﻿TITLE_26_H
