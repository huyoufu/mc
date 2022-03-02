//
// Created by 户有福 on 2022/3/3.
//

#ifndef MC_MC_H
#define MC_MC_H
#include <stdio.h>
#define mcAssert(_e) ((_e)?(void)0 : (_mcAssert(#_e,__FILE__,__LINE__)))
void _mcAssert(const char *estr, const char *file, int line);
#endif //MC_MC_H
