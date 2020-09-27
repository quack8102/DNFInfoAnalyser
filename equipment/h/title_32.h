#ifndef TITLE_32_H
#define TITLE_32_H

#include "equipment.h"

class Title_32 : public Equipment { // 伊希斯的苍穹之歌
public:
	Title_32(){}
	void operator() (Character &model);
};

#endif // TITLE_32_H
