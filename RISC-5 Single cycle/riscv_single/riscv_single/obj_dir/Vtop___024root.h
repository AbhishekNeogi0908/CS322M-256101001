// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(MemWrite,0,0);
    CData/*4:0*/ top__DOT__rvsingle__DOT__ALUControl;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__reset__0;
    CData/*0:0*/ __VactContinue;
    SData/*10:0*/ top__DOT__rvsingle__DOT__c__DOT__md__DOT__controls;
    VL_OUT(WriteData,31,0);
    VL_OUT(DataAdr,31,0);
    IData/*31:0*/ top__DOT__PC;
    IData/*31:0*/ top__DOT__Instr;
    IData/*31:0*/ top__DOT__rvsingle__DOT__dp__DOT__PCNext;
    IData/*31:0*/ top__DOT__rvsingle__DOT__dp__DOT__ImmExt;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 32> top__DOT__rvsingle__DOT__dp__DOT__rf__DOT__rf;
    VlUnpacked<IData/*31:0*/, 64> top__DOT__imem__DOT__RAM;
    VlUnpacked<IData/*31:0*/, 64> top__DOT__dmem__DOT__RAM;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
