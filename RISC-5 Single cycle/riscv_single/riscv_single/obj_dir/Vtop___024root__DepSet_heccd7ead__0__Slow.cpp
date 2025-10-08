// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    // Body
    Vtop___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = vlSelf->reset;
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    // Init
    VlWide<4>/*127:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e747874U;
    __Vtemp_1[1U] = 0x74657374U;
    __Vtemp_1[2U] = 0x69736376U;
    __Vtemp_1[3U] = 0x72U;
    VL_READMEM_N(true, 32, 64, 0, VL_CVT_PACK_STR_NW(4, __Vtemp_1)
                 ,  &(vlSelf->top__DOT__imem__DOT__RAM)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("riscvsingle.sv", 120, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtop___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

extern const VlUnpacked<SData/*10:0*/, 128> Vtop__ConstPool__TABLE_h1930df51_0;
extern const VlUnpacked<CData/*4:0*/, 64> Vtop__ConstPool__TABLE_h75932201_0;

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ top__DOT__rvsingle__DOT__dp__DOT__SrcA;
    top__DOT__rvsingle__DOT__dp__DOT__SrcA = 0;
    IData/*31:0*/ top__DOT__rvsingle__DOT__dp__DOT__SrcB;
    top__DOT__rvsingle__DOT__dp__DOT__SrcB = 0;
    IData/*31:0*/ top__DOT__rvsingle__DOT__dp__DOT__alu__DOT__sum;
    top__DOT__rvsingle__DOT__dp__DOT__alu__DOT__sum = 0;
    CData/*0:0*/ top__DOT__rvsingle__DOT__dp__DOT__alu__DOT____VdfgTmp_hbb786b22__0;
    top__DOT__rvsingle__DOT__dp__DOT__alu__DOT____VdfgTmp_hbb786b22__0 = 0;
    IData/*31:0*/ __VdfgTmp_h171936a9__0;
    __VdfgTmp_h171936a9__0 = 0;
    CData/*6:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*5:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    // Body
    vlSelf->top__DOT__Instr = vlSelf->top__DOT__imem__DOT__RAM
        [(0x3fU & (vlSelf->top__DOT__PC >> 2U))];
    vlSelf->WriteData = ((0U == (0x1fU & (vlSelf->top__DOT__Instr 
                                          >> 0x14U)))
                          ? 0U : vlSelf->top__DOT__rvsingle__DOT__dp__DOT__rf__DOT__rf
                         [(0x1fU & (vlSelf->top__DOT__Instr 
                                    >> 0x14U))]);
    __VdfgTmp_h171936a9__0 = vlSelf->top__DOT__rvsingle__DOT__dp__DOT__rf__DOT__rf
        [(0x1fU & (vlSelf->top__DOT__Instr >> 0xfU))];
    __Vtableidx1 = (0x7fU & vlSelf->top__DOT__Instr);
    vlSelf->top__DOT__rvsingle__DOT__c__DOT__md__DOT__controls 
        = Vtop__ConstPool__TABLE_h1930df51_0[__Vtableidx1];
    top__DOT__rvsingle__DOT__dp__DOT__alu__DOT____VdfgTmp_hbb786b22__0 
        = ((0U != (0x1fU & (vlSelf->top__DOT__Instr 
                            >> 0xfU))) & (__VdfgTmp_h171936a9__0 
                                          >> 0x1fU));
    top__DOT__rvsingle__DOT__dp__DOT__SrcA = ((0U == 
                                               (0x1fU 
                                                & (vlSelf->top__DOT__Instr 
                                                   >> 0xfU)))
                                               ? 0U
                                               : __VdfgTmp_h171936a9__0);
    vlSelf->MemWrite = (1U & ((IData)(vlSelf->top__DOT__rvsingle__DOT__c__DOT__md__DOT__controls) 
                              >> 6U));
    __Vtableidx2 = ((0x38U & (vlSelf->top__DOT__Instr 
                              >> 9U)) | ((4U & (vlSelf->top__DOT__Instr 
                                                >> 0x17U)) 
                                         | (3U & ((IData)(vlSelf->top__DOT__rvsingle__DOT__c__DOT__md__DOT__controls) 
                                                  >> 1U))));
    vlSelf->top__DOT__rvsingle__DOT__ALUControl = Vtop__ConstPool__TABLE_h75932201_0
        [__Vtableidx2];
    vlSelf->top__DOT__rvsingle__DOT__dp__DOT__ImmExt 
        = ((0x200U & (IData)(vlSelf->top__DOT__rvsingle__DOT__c__DOT__md__DOT__controls))
            ? ((0x100U & (IData)(vlSelf->top__DOT__rvsingle__DOT__c__DOT__md__DOT__controls))
                ? (((- (IData)((vlSelf->top__DOT__Instr 
                                >> 0x1fU))) << 0x14U) 
                   | ((0xff000U & vlSelf->top__DOT__Instr) 
                      | ((0x800U & (vlSelf->top__DOT__Instr 
                                    >> 9U)) | (0x7feU 
                                               & (vlSelf->top__DOT__Instr 
                                                  >> 0x14U)))))
                : (((- (IData)((vlSelf->top__DOT__Instr 
                                >> 0x1fU))) << 0xcU) 
                   | ((0x800U & (vlSelf->top__DOT__Instr 
                                 << 4U)) | ((0x7e0U 
                                             & (vlSelf->top__DOT__Instr 
                                                >> 0x14U)) 
                                            | (0x1eU 
                                               & (vlSelf->top__DOT__Instr 
                                                  >> 7U))))))
            : ((0x100U & (IData)(vlSelf->top__DOT__rvsingle__DOT__c__DOT__md__DOT__controls))
                ? (((- (IData)((vlSelf->top__DOT__Instr 
                                >> 0x1fU))) << 0xcU) 
                   | ((0xfe0U & (vlSelf->top__DOT__Instr 
                                 >> 0x14U)) | (0x1fU 
                                               & (vlSelf->top__DOT__Instr 
                                                  >> 7U))))
                : (((- (IData)((vlSelf->top__DOT__Instr 
                                >> 0x1fU))) << 0xcU) 
                   | (vlSelf->top__DOT__Instr >> 0x14U))));
    top__DOT__rvsingle__DOT__dp__DOT__SrcB = ((0x80U 
                                               & (IData)(vlSelf->top__DOT__rvsingle__DOT__c__DOT__md__DOT__controls))
                                               ? vlSelf->top__DOT__rvsingle__DOT__dp__DOT__ImmExt
                                               : vlSelf->WriteData);
    top__DOT__rvsingle__DOT__dp__DOT__alu__DOT__sum 
        = (top__DOT__rvsingle__DOT__dp__DOT__SrcA + 
           (((1U & (IData)(vlSelf->top__DOT__rvsingle__DOT__ALUControl))
              ? (~ top__DOT__rvsingle__DOT__dp__DOT__SrcB)
              : top__DOT__rvsingle__DOT__dp__DOT__SrcB) 
            + (1U & (IData)(vlSelf->top__DOT__rvsingle__DOT__ALUControl))));
    vlSelf->DataAdr = ((0x10U & (IData)(vlSelf->top__DOT__rvsingle__DOT__ALUControl))
                        ? ((8U & (IData)(vlSelf->top__DOT__rvsingle__DOT__ALUControl))
                            ? 0U : ((4U & (IData)(vlSelf->top__DOT__rvsingle__DOT__ALUControl))
                                     ? 0U : ((2U & (IData)(vlSelf->top__DOT__rvsingle__DOT__ALUControl))
                                              ? 0U : 
                                             ((1U & (IData)(vlSelf->top__DOT__rvsingle__DOT__ALUControl))
                                               ? (VL_LTES_III(32, 0U, top__DOT__rvsingle__DOT__dp__DOT__SrcA)
                                                   ? top__DOT__rvsingle__DOT__dp__DOT__SrcA
                                                   : 
                                                  (- top__DOT__rvsingle__DOT__dp__DOT__SrcA))
                                               : ((0U 
                                                   == 
                                                   (0x1fU 
                                                    & top__DOT__rvsingle__DOT__dp__DOT__SrcB))
                                                   ? top__DOT__rvsingle__DOT__dp__DOT__SrcA
                                                   : 
                                                  ((top__DOT__rvsingle__DOT__dp__DOT__SrcA 
                                                    >> 
                                                    (0x1fU 
                                                     & top__DOT__rvsingle__DOT__dp__DOT__SrcB)) 
                                                   | VL_SHIFTL_III(32,32,32, top__DOT__rvsingle__DOT__dp__DOT__SrcA, 
                                                                   ((IData)(0x20U) 
                                                                    - 
                                                                    (0x1fU 
                                                                     & top__DOT__rvsingle__DOT__dp__DOT__SrcB)))))))))
                        : ((8U & (IData)(vlSelf->top__DOT__rvsingle__DOT__ALUControl))
                            ? ((4U & (IData)(vlSelf->top__DOT__rvsingle__DOT__ALUControl))
                                ? ((2U & (IData)(vlSelf->top__DOT__rvsingle__DOT__ALUControl))
                                    ? ((1U & (IData)(vlSelf->top__DOT__rvsingle__DOT__ALUControl))
                                        ? ((0U == (0x1fU 
                                                   & top__DOT__rvsingle__DOT__dp__DOT__SrcB))
                                            ? top__DOT__rvsingle__DOT__dp__DOT__SrcA
                                            : ((top__DOT__rvsingle__DOT__dp__DOT__SrcA 
                                                << 
                                                (0x1fU 
                                                 & top__DOT__rvsingle__DOT__dp__DOT__SrcB)) 
                                               | VL_SHIFTR_III(32,32,32, top__DOT__rvsingle__DOT__dp__DOT__SrcA, 
                                                               ((IData)(0x20U) 
                                                                - 
                                                                (0x1fU 
                                                                 & top__DOT__rvsingle__DOT__dp__DOT__SrcB)))))
                                        : ((top__DOT__rvsingle__DOT__dp__DOT__SrcA 
                                            > top__DOT__rvsingle__DOT__dp__DOT__SrcB)
                                            ? top__DOT__rvsingle__DOT__dp__DOT__SrcA
                                            : top__DOT__rvsingle__DOT__dp__DOT__SrcB))
                                    : ((1U & (IData)(vlSelf->top__DOT__rvsingle__DOT__ALUControl))
                                        ? ((top__DOT__rvsingle__DOT__dp__DOT__SrcA 
                                            < top__DOT__rvsingle__DOT__dp__DOT__SrcB)
                                            ? top__DOT__rvsingle__DOT__dp__DOT__SrcA
                                            : top__DOT__rvsingle__DOT__dp__DOT__SrcB)
                                        : (VL_GTS_III(32, top__DOT__rvsingle__DOT__dp__DOT__SrcA, top__DOT__rvsingle__DOT__dp__DOT__SrcB)
                                            ? top__DOT__rvsingle__DOT__dp__DOT__SrcA
                                            : top__DOT__rvsingle__DOT__dp__DOT__SrcB)))
                                : ((2U & (IData)(vlSelf->top__DOT__rvsingle__DOT__ALUControl))
                                    ? ((1U & (IData)(vlSelf->top__DOT__rvsingle__DOT__ALUControl))
                                        ? (VL_LTS_III(32, top__DOT__rvsingle__DOT__dp__DOT__SrcA, top__DOT__rvsingle__DOT__dp__DOT__SrcB)
                                            ? top__DOT__rvsingle__DOT__dp__DOT__SrcA
                                            : top__DOT__rvsingle__DOT__dp__DOT__SrcB)
                                        : (~ (top__DOT__rvsingle__DOT__dp__DOT__SrcA 
                                              ^ top__DOT__rvsingle__DOT__dp__DOT__SrcB)))
                                    : ((1U & (IData)(vlSelf->top__DOT__rvsingle__DOT__ALUControl))
                                        ? (top__DOT__rvsingle__DOT__dp__DOT__SrcA 
                                           | (~ top__DOT__rvsingle__DOT__dp__DOT__SrcB))
                                        : (top__DOT__rvsingle__DOT__dp__DOT__SrcA 
                                           & (~ top__DOT__rvsingle__DOT__dp__DOT__SrcB)))))
                            : ((4U & (IData)(vlSelf->top__DOT__rvsingle__DOT__ALUControl))
                                ? ((2U & (IData)(vlSelf->top__DOT__rvsingle__DOT__ALUControl))
                                    ? ((1U & (IData)(vlSelf->top__DOT__rvsingle__DOT__ALUControl))
                                        ? (top__DOT__rvsingle__DOT__dp__DOT__SrcA 
                                           >> (0x1fU 
                                               & top__DOT__rvsingle__DOT__dp__DOT__SrcB))
                                        : (top__DOT__rvsingle__DOT__dp__DOT__SrcA 
                                           << (0x1fU 
                                               & top__DOT__rvsingle__DOT__dp__DOT__SrcB)))
                                    : ((1U & (IData)(vlSelf->top__DOT__rvsingle__DOT__ALUControl))
                                        ? (VL_SHIFTR_III(32,32,32, top__DOT__rvsingle__DOT__dp__DOT__alu__DOT__sum, 0x1fU) 
                                           ^ (1U & 
                                              ((~ ((IData)(vlSelf->top__DOT__rvsingle__DOT__ALUControl) 
                                                   ^ 
                                                   ((IData)(top__DOT__rvsingle__DOT__dp__DOT__alu__DOT____VdfgTmp_hbb786b22__0) 
                                                    ^ 
                                                    (top__DOT__rvsingle__DOT__dp__DOT__SrcB 
                                                     >> 0x1fU)))) 
                                               & (((IData)(top__DOT__rvsingle__DOT__dp__DOT__alu__DOT____VdfgTmp_hbb786b22__0) 
                                                   ^ 
                                                   (top__DOT__rvsingle__DOT__dp__DOT__alu__DOT__sum 
                                                    >> 0x1fU)) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (6U 
                                                               & (IData)(vlSelf->top__DOT__rvsingle__DOT__ALUControl)))) 
                                                     | (IData)(
                                                               (1U 
                                                                == 
                                                                (3U 
                                                                 & (IData)(vlSelf->top__DOT__rvsingle__DOT__ALUControl)))))))))
                                        : (top__DOT__rvsingle__DOT__dp__DOT__SrcA 
                                           ^ top__DOT__rvsingle__DOT__dp__DOT__SrcB)))
                                : ((2U & (IData)(vlSelf->top__DOT__rvsingle__DOT__ALUControl))
                                    ? ((1U & (IData)(vlSelf->top__DOT__rvsingle__DOT__ALUControl))
                                        ? (top__DOT__rvsingle__DOT__dp__DOT__SrcA 
                                           | top__DOT__rvsingle__DOT__dp__DOT__SrcB)
                                        : (top__DOT__rvsingle__DOT__dp__DOT__SrcA 
                                           & top__DOT__rvsingle__DOT__dp__DOT__SrcB))
                                    : top__DOT__rvsingle__DOT__dp__DOT__alu__DOT__sum))));
    vlSelf->top__DOT__rvsingle__DOT__dp__DOT__PCNext 
        = ((1U & ((((IData)(vlSelf->top__DOT__rvsingle__DOT__c__DOT__md__DOT__controls) 
                    >> 3U) & (0U == vlSelf->DataAdr)) 
                  | (IData)(vlSelf->top__DOT__rvsingle__DOT__c__DOT__md__DOT__controls)))
            ? (vlSelf->top__DOT__PC + vlSelf->top__DOT__rvsingle__DOT__dp__DOT__ImmExt)
            : ((IData)(4U) + vlSelf->top__DOT__PC));
}

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk or posedge reset)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk or posedge reset)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->WriteData = VL_RAND_RESET_I(32);
    vlSelf->DataAdr = VL_RAND_RESET_I(32);
    vlSelf->MemWrite = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__PC = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__Instr = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__rvsingle__DOT__ALUControl = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__rvsingle__DOT__c__DOT__md__DOT__controls = VL_RAND_RESET_I(11);
    vlSelf->top__DOT__rvsingle__DOT__dp__DOT__PCNext = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__rvsingle__DOT__dp__DOT__ImmExt = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__rvsingle__DOT__dp__DOT__rf__DOT__rf[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->top__DOT__imem__DOT__RAM[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->top__DOT__dmem__DOT__RAM[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = VL_RAND_RESET_I(1);
}
