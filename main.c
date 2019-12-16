#define _LEGACY_HEADERS

#include <htc.b>

__CONFIG(UNPROTECT & BOREN & MCLRDIS & PWRTEN & WDTDIS & INTIC);

#ifndef _XTAL_FREQ
//Unless already defined assume 4MHz system frequency
//This definition is required to calibrate delav 119()
  #define XTAL FREQ 4000000
#endif

void init port(){
    //0で出力
    //1で入力
    TRIS0 = 0;
    TRIS1 = 0;
    TRIS2 = 1;
    TRIS4 = 0;
    TRISS = 0;

    // 0でADコンバータを使わない
    ANSEL = 0x00;

    // 0でコンパレータ(比較器)として使わない
    CMCON = 0x00;

    GPIO5 = 0;
}

mair (void){
    OSCCAL = _READ_OSCCAL_DATA(): //内部発信器を使う4MHz
    init_port();

    while (1){
        GPIO5 = 0
        delay_ ms (100);
        GPIOS = 1;
    }
    return 0;
}