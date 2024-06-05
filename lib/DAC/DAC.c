#include "MKL25Z4.h"
#include "DAC.h"
void DAC_Init(){
    SIM-> SCGC6 |= SIM_SCGC6_DAC0_MASK;
    DAC0 -> C0 = DAC_C0_DACEN_MASK | DAC_C0_DACRFS_MASK;
}
void DAC_Convertion(int valor){
    DAC0->DAT[0].DATH = DAC_DATH_DATA1(valor >> 8);
    DAC0->DAT[0].DATL = DAC_DATL_DATA0(valor & 0xFF);
}