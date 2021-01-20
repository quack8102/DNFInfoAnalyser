#include "attrcalculator.h"
#include <QVector>

namespace CALC {
int getBaseSTR(int level, int quality, int type, int armorType/* = 0*/) {
    if (type <= 4) {
        if (level == 100) {
            if (quality == 0) {
                if (armorType == 1) {
                    if (type == 1) return 100;//158
                    if (type == 0) return 100;//146
                    if (type == 2) return 100;//158
                    if (type == 4) return 100;//135
                    if (type == 3) return 100;//135
                } else if (armorType == 2) {
                    if (type == 1) return 149;//149
                    if (type == 0) return 139;//139
                    if (type == 2) return 149;//149
                    if (type == 4) return 130;//130
                    if (type == 3) return 130;//130
                } else if (armorType == 3) {
                    if (type == 1) return 158;//139
                    if (type == 0) return 146;//131
                    if (type == 2) return 158;//139
                    if (type == 4) return 135;//123
                    if (type == 3) return 135;//123
                } else if (armorType == 4) {
                    if (type == 1) return 154;//139
                    if (type == 0) return 143;//131
                    if (type == 2) return 154;//139
                    if (type == 4) return 132;//123
                    if (type == 3) return 132;//123
                } else if (armorType == 5) {
                    if (type == 1) return 149;//149
                    if (type == 0) return 139;//139
                    if (type == 2) return 149;//149
                    if (type == 4) return 130;//130
                    if (type == 3) return 130;//130
                }
            } else if (quality == -1) {
                if (armorType == 1) {
                    if (type == 1) return 0;//57
                    if (type == 0) return 0;//45
                    if (type == 2) return 0;//57
                    if (type == 4) return 0;//34
                    if (type == 3) return 0;//34
                } else if (armorType == 2) {
                    if (type == 1) return 47;//47
                    if (type == 0) return 39;//39
                    if (type == 2) return 47;//47
                    if (type == 4) return 29;//29
                    if (type == 3) return 29;//29
                } else if (armorType == 3) {
                    if (type == 1) return 57;//37
                    if (type == 0) return 45;//31
                    if (type == 2) return 57;//37
                    if (type == 4) return 34;//23
                    if (type == 3) return 34;//23
                } else if (armorType == 4) {
                    if (type == 1) return 52;//37
                    if (type == 0) return 42;//31
                    if (type == 2) return 57;//37
                    if (type == 4) return 31;//23
                    if (type == 3) return 31;//23
                } else if (armorType == 5) {
                    if (type == 1) return 47;//47
                    if (type == 0) return 39;//39
                    if (type == 2) return 47;//47
                    if (type == 4) return 29;//29
                    if (type == 3) return 29;//29
                }
            } else if (quality == 1) {
                if (armorType == 1) return 100;//160
                if (armorType == 2) return 150;//150
                if (armorType == 3) return 160;//140
                if (armorType == 4) return 155;//140
                if (armorType == 5) return 150;//150
            }
        }
    } else if (type >= 7) {
        if (level == 100) {
            if (quality == 0) {
                if (type == 7) return 147;//100
                if (type == 8) return 100;//147
                if (type == 9) return 146;//146
                if (type == 10) return 171;//171
                if (type == 11) return 169;//169
                if (type == 12) return 169;//169
            } else if (quality == -1) {
                if (type == 7) return 46;//0
                if (type == 8) return 0;//46
                if (type == 9) return 45;//45
                if (type == 10) return 68;//68
                if (type == 11) return 67;//67
                if (type == 12) return 67;//67
            } else if (quality == 1) {
                if (type == 7) return 149;//100
                if (type == 11) return 171;//171
            }
        } else if (level == 95) {
            if (quality == 0) {
                if (type == 7) return 45;//0
                if (type == 8) return 0;//45
                if (type == 9) return 44;//44
                if (type == 10) return 67;//67
                if (type == 11) return 66;//66
                if (type == 12) return 66;//66
            }
        } else if (level == 85) {
            if (quality == 0) {
                if (type == 7) return 41;//0
                if (type == 8) return 0;//41
                if (type == 10) return 62;//62
            }
        }
    }
    return 0;
}

int getBaseINT(int level, int quality, int type, int armorType/* = 0*/) {
    if (type <= 4) {
        if (level == 100) {
            if (quality == 0) {
                if (armorType == 1) {
                    if (type == 1) return 158;
                    if (type == 0) return 146;
                    if (type == 2) return 158;
                    if (type == 4) return 135;
                    if (type == 3) return 135;
                } else if (armorType == 2) {
                    if (type == 1) return 149;
                    if (type == 0) return 139;
                    if (type == 2) return 149;
                    if (type == 4) return 130;
                    if (type == 3) return 130;
                } else if (armorType == 3) {
                    if (type == 1) return 139;
                    if (type == 0) return 131;
                    if (type == 2) return 139;
                    if (type == 4) return 123;
                    if (type == 3) return 123;
                } else if (armorType == 4) {
                    if (type == 1) return 139;
                    if (type == 0) return 131;
                    if (type == 2) return 139;
                    if (type == 4) return 123;
                    if (type == 3) return 123;
                } else if (armorType == 5) {
                    if (type == 1) return 149;
                    if (type == 0) return 139;
                    if (type == 2) return 149;
                    if (type == 4) return 130;
                    if (type == 3) return 130;
                }
            } else if (quality == -1) {
                if (armorType == 1) {
                    if (type == 1) return 57;
                    if (type == 0) return 45;
                    if (type == 2) return 57;
                    if (type == 4) return 34;
                    if (type == 3) return 34;
                } else if (armorType == 2) {
                    if (type == 1) return 47;
                    if (type == 0) return 39;
                    if (type == 2) return 47;
                    if (type == 4) return 29;
                    if (type == 3) return 29;
                } else if (armorType == 3) {
                    if (type == 1) return 37;
                    if (type == 0) return 31;
                    if (type == 2) return 37;
                    if (type == 4) return 23;
                    if (type == 3) return 23;
                } else if (armorType == 4) {
                    if (type == 1) return 37;
                    if (type == 0) return 31;
                    if (type == 2) return 37;
                    if (type == 4) return 23;
                    if (type == 3) return 23;
                } else if (armorType == 5) {
                    if (type == 1) return 47;
                    if (type == 0) return 39;
                    if (type == 2) return 47;
                    if (type == 4) return 29;
                    if (type == 3) return 29;
                }
            } else if (quality == 1) {
                if (armorType == 1) return 160;
                if (armorType == 2) return 150;
                if (armorType == 3) return 140;
                if (armorType == 4) return 140;
                if (armorType == 5) return 150;
            }
        }
    } else if (type >= 7) {
        if (level == 100) {
            if (quality == 0) {
                if (type == 7) return 100;
                if (type == 8) return 147;
                if (type == 9) return 146;
                if (type == 10) return 171;
                if (type == 11) return 169;
                if (type == 12) return 169;
            } else if (quality == -1) {
                if (type == 7) return 0;
                if (type == 8) return 46;
                if (type == 9) return 45;
                if (type == 10) return 68;
                if (type == 11) return 67;
                if (type == 12) return 67;
            } else if (quality == 1) {
                if (type == 7) return 100;
                if (type == 11) return 171;
            }
        } else if (level == 95) {
            if (quality == 0) {
                if (type == 7) return 0;
                if (type == 8) return 45;
                if (type == 9) return 44;
                if (type == 10) return 67;
                if (type == 11) return 66;
                if (type == 12) return 66;
            }
        } else if (level == 85) {
            if (quality == 0) {
                if (type == 7) return 0;
                if (type == 8) return 41;
                if (type == 10) return 62;
            }
        }
    }
    return 0;
}

double getMasterAttr(int level, int quality, int refoLV, int type) {
    if (type <= 4) {
        double kk = 0, bouns = 0;
        if (type == 0) kk = 0.2;
        else if (type == 1) kk = 0.3;
        else if (type == 2) kk = 0.25;
        else if (type == 3) kk = 0.1;
        else if (type == 4) kk = 0.15;
        if (quality == -1) bouns = 14;
        else if (quality == 0) bouns = 17;
        else if (quality == 1) bouns = 18;
        return (20 + 2.5 * (level + bouns + int(refoLV / 3))) * kk;
    }
    return 0;
}

int getRefoAttr(int level, int quality, int refoLV, int type) {
    int qk = 0, tt = 0;
    double kk = 0;
    QVector<int> data{0, 60, 90, 120, 150, 180, 210, 247, 285, 322, 360, 675, 1013, 1350, 2025, 2813, 3600, 4950, 6300, 7650, 9113};
    if (type == 9 || type == 12) {
        if (quality == -1) qk = 29, kk = 1.35;
        else if (quality == 0) qk = 30, kk = 1.45;
        tt = data.at(refoLV);
        return int((level + qk) * kk * tt / 2400.0);
    }
    return 0;
}

int getRefoAtk(int level, int quality, int refoLV, int type, double wk/* = 0*/) {
    int qk = 0;
    double kk = 0, tt = 0, eps = 1e-6;
    if (type == 11) {
        if (quality == -1) qk = 29, kk = 1.35;
        else if (quality == 0) qk = 30, kk = 1.45;
        else if (quality == 1) qk = 31, kk = 1.55;
        QVector<int> data{0, 83, 124, 166, 207, 248, 314, 370, 426, 482, 621, 970, 1455, 1941, 2911, 4043, 5175, 7116, 9056, 10997, 13099};
        tt = data.at(refoLV);
        return int((level + qk) * kk * tt / 2400.0);
    } else if (type == 5) {
        if (quality == -1) qk = 13, kk = 1.35;
        else if (quality == 0) qk = 14, kk = 1.45;
        if (wk > 1 - eps && wk < 1 + eps) {
            QVector<int> data{0, 2, 3, 4, 6, 8, 13, 18, 25, 32};
            tt = data.at(refoLV);
            return int((level + qk) / 8.0 * kk * tt + 0.5);
        } else {
            QVector<double> data{0, 2, 2.6, 3.6, 4.7, 5.8, 6.9, 8.2, 11, 14.6, 18.7, 26.9, 36.7, 43, 49.2, 55.4, 61.7, 68, 74.3, 80.6, 86.9};
            tt = data.at(refoLV);
            return int((level + qk) / 8.0 * kk * tt * wk);
        }
    }
    return 0;
}

int getAmpAttr(int level, int quality, int ampLV) {
    int qk = 46;
    int qb = 0;
    double kk = 0, tt = 0;
    if (quality == -1) qb = 6, kk = 1.4;
    else if (quality == 0) qb = 7, kk = 1.5;
    else if (quality == 1) qb = 8, kk = 1.6;
    QVector<double> data{0, 1, 2, 3, 4, 6, 8, 10, 12, 13, 17, 33, 50, 67, 108, 150, 192, 267, 342, 417, 499.9};
    tt = data.at(ampLV);
    int res = int((level + qk) * kk * tt / 100.0) + qb;
    if (level == 100 && quality == 0) {
        if (ampLV <= 7) res += 5;
        if (ampLV == 8) res += 27;
        if (ampLV == 9) res += 38;
        if (ampLV == 10) res += 44;
        if (ampLV == 11) res += 24;
        if (ampLV == 12 || ampLV == 13) res += 10;
    } else if (level == 100 && quality == 1) {
        if (ampLV <= 7) res += 5;
        if (ampLV == 8) res += 28;
        if (ampLV == 9) res += 40;
        if (ampLV == 10) res += 47;
        if (ampLV == 11) res += 26;
        if (ampLV == 12 || ampLV == 13) res += 10;
    }
    return res;
}
}
