#ifndef ATTRCACULATOR_H
#define ATTRCACULATOR_H

namespace CALC {
int getBaseSTR(int level, int quality, int type, int armorType = 0);
int getBaseINT(int level, int quality, int type, int armorType = 0);
double getMasterAttr(int level, int quality, int refoLV, int type);
int getRefoAttr(int level, int quality, int refoLV, int type);
int getRefoAtk(int level, int quality, int refoLV, int type, double wk = 0);
int getAmpAttr(int level, int quality, int ampLV);
}

#endif // ATTRCACULATOR_H
