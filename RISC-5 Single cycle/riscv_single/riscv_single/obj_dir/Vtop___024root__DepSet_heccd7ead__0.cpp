// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vdlyvdim0__top__DOT__rvsingle__DOT__dp__DOT__rf__DOT__rf__v0;
    __Vdlyvdim0__top__DOT__rvsingle__DOT__dp__DOT__rf__DOT__rf__v0 = 0;
    IData/*31:0*/ __Vdlyvval__top__DOT__rvsingle__DOT__dp__DOT__rf__DOT__rf__v0;
    __Vdlyvval__top__DOT__rvsingle__DOT__dp__DOT__rf__DOT__rf__v0 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__rvsingle__DOT__dp__DOT__rf__DOT__rf__v0;
    __Vdlyvset__top__DOT__rvsingle__DOT__dp__DOT__rf__DOT__rf__v0 = 0;
    CData/*5:0*/ __Vdlyvdim0__top__DOT__dmem__DOT__RAM__v0;
    __Vdlyvdim0__top__DOT__dmem__DOT__RAM__v0 = 0;
    IData/*31:0*/ __Vdlyvval__top__DOT__dmem__DOT__RAM__v0;
    __Vdlyvval__top__DOT__dmem__DOT__RAM__v0 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__dmem__DOT__RAM__v0;
    __Vdlyvset__top__DOT__dmem__DOT__RAM__v0 = 0;
    // Body
    __Vdlyvset__top__DOT__dmem__DOT__RAM__v0 = 0U;
    __Vdlyvset__top__DOT__rvsingle__DOT__dp__DOT__rf__DOT__rf__v0 = 0U;
    if (vlSelf->MemWrite) {
        __Vdlyvval__top__DOT__dmem__DOT__RAM__v0 = vlSelf->WriteData;
        __Vdlyvset__top__DOT__dmem__DOT__RAM__v0 = 1U;
        __Vdlyvdim0__top__DOT__dmem__DOT__RAM__v0 = 
            (0x3fU & (vlSelf->DataAdr >> 2U));
    }
    if ((0x400U & (IData)(vlSelf->top__DOT__rvsingle__DOT__c__DOT__md__DOT__controls))) {
        __Vdlyvval__top__DOT__rvsingle__DOT__dp__DOT__rf__DOT__rf__v0 
            = ((0x20U & (IData)(vlSelf->top__DOT__rvsingle__DOT__c__DOT__md__DOT__controls))
                ? ((IData)(4U) + vlSelf->top__DOT__PC)
                : ((0x10U & (IData)(vlSelf->top__DOT__rvsingle__DOT__c__DOT__md__DOT__controls))
                    ? vlSelf->top__DOT__dmem__DOT__RAM
                   [(0x3fU & (vlSelf->DataAdr >> 2U))]
                    : vlSelf->DataAdr));
        __Vdlyvset__top__DOT__rvsingle__DOT__dp__DOT__rf__DOT__rf__v0 = 1U;
        __Vdlyvdim0__top__DOT__rvsingle__DOT__dp__DOT__rf__DOT__rf__v0 
            = (0x1fU & (vlSelf->top__DOT__Instr >> 7U));
    }
    if (__Vdlyvset__top__DOT__dmem__DOT__RAM__v0) {
        vlSelf->top__DOT__dmem__DOT__RAM[__Vdlyvdim0__top__DOT__dmem__DOT__RAM__v0] 
            = __Vdlyvval__top__DOT__dmem__DOT__RAM__v0;
    }
    if (__Vdlyvset__top__DOT__rvsingle__DOT__dp__DOT__rf__DOT__rf__v0) {
        vlSelf->top__DOT__rvsingle__DOT__dp__DOT__rf__DOT__rf[__Vdlyvdim0__top__DOT__rvsingle__DOT__dp__DOT__rf__DOT__rf__v0] 
            = __Vdlyvval__top__DOT__rvsingle__DOT__dp__DOT__rf__DOT__rf__v0;
    }
}

extern const VlUnpacked<SData/*10:0*/, 128> Vtop__ConstPool__TABLE_h1930df51_0;
extern const VlUnpacked<CData/*4:0*/, 64> Vtop__ConstPool__TABLE_h75932201_0;

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    // Init
    CData/*6:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*5:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    // Body
    vlSelf->top__DOT__PC = ((IData)(vlSelf->reset) ? 0U
                             : vlSelf->top__DOT__rvsingle__DOT__dp__DOT__PCNext);
    vlSelf->top__DOT__Instr = vlSelf->top__DOT__imem__DOT__RAM
        [(0x3fU & (vlSelf->top__DOT__PC >> 2U))];
    __Vtableidx1 = (0x7fU & vlSelf->top__DOT__Instr);
    vlSelf->top__DOT__rvsingle__DOT__c__DOT__md__DOT__controls 
        = Vtop__ConstPool__TABLE_h1930df51_0[__Vtableidx1];
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
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
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
    // Body
    vlSelf->WriteData = ((0U == (0x1fU & (vlSelf->top__DOT__Instr 
                                          >> 0x14U)))
                          ? 0U : vlSelf->top__DOT__rvsingle__DOT__dp__DOT__rf__DOT__rf
                         [(0x1fU & (vlSelf->top__DOT__Instr 
                                    >> 0x14U))]);
    __VdfgTmp_h171936a9__0 = vlSelf->top__DOT__rvsingle__DOT__dp__DOT__rf__DOT__rf
        [(0x1fU & (vlSelf->top__DOT__Instr >> 0xfU))];
    top__DOT__rvsingle__DOT__dp__DOT__SrcB = ((0x80U 
                                               & (IData)(vlSelf->top__DOT__rvsingle__DOT__c__DOT__md__DOT__controls))
                                               ? vlSelf->top__DOT__rvsingle__DOT__dp__DOT__ImmExt
                                               : vlSelf->WriteData);
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

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((3ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_comb__TOP__0(vlSelf);
    }
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("riscvsingle.sv", 120, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("riscvsingle.sv", 120, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtop___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtop___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
