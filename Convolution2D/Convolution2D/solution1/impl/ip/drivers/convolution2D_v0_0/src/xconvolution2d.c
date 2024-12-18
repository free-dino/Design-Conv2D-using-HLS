// ==============================================================
// File generated on Wed Dec 18 21:02:53 +0700 2024
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xconvolution2d.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XConvolution2d_CfgInitialize(XConvolution2d *InstancePtr, XConvolution2d_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Conv_io_BaseAddress = ConfigPtr->Conv_io_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XConvolution2d_Start(XConvolution2d *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConvolution2d_ReadReg(InstancePtr->Conv_io_BaseAddress, XCONVOLUTION2D_CONV_IO_ADDR_AP_CTRL) & 0x80;
    XConvolution2d_WriteReg(InstancePtr->Conv_io_BaseAddress, XCONVOLUTION2D_CONV_IO_ADDR_AP_CTRL, Data | 0x01);
}

u32 XConvolution2d_IsDone(XConvolution2d *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConvolution2d_ReadReg(InstancePtr->Conv_io_BaseAddress, XCONVOLUTION2D_CONV_IO_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XConvolution2d_IsIdle(XConvolution2d *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConvolution2d_ReadReg(InstancePtr->Conv_io_BaseAddress, XCONVOLUTION2D_CONV_IO_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XConvolution2d_IsReady(XConvolution2d *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConvolution2d_ReadReg(InstancePtr->Conv_io_BaseAddress, XCONVOLUTION2D_CONV_IO_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XConvolution2d_EnableAutoRestart(XConvolution2d *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConvolution2d_WriteReg(InstancePtr->Conv_io_BaseAddress, XCONVOLUTION2D_CONV_IO_ADDR_AP_CTRL, 0x80);
}

void XConvolution2d_DisableAutoRestart(XConvolution2d *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConvolution2d_WriteReg(InstancePtr->Conv_io_BaseAddress, XCONVOLUTION2D_CONV_IO_ADDR_AP_CTRL, 0);
}

void XConvolution2d_Set_kernel_0_0(XConvolution2d *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConvolution2d_WriteReg(InstancePtr->Conv_io_BaseAddress, XCONVOLUTION2D_CONV_IO_ADDR_KERNEL_0_0_DATA, Data);
}

u32 XConvolution2d_Get_kernel_0_0(XConvolution2d *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConvolution2d_ReadReg(InstancePtr->Conv_io_BaseAddress, XCONVOLUTION2D_CONV_IO_ADDR_KERNEL_0_0_DATA);
    return Data;
}

void XConvolution2d_Set_kernel_0_1(XConvolution2d *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConvolution2d_WriteReg(InstancePtr->Conv_io_BaseAddress, XCONVOLUTION2D_CONV_IO_ADDR_KERNEL_0_1_DATA, Data);
}

u32 XConvolution2d_Get_kernel_0_1(XConvolution2d *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConvolution2d_ReadReg(InstancePtr->Conv_io_BaseAddress, XCONVOLUTION2D_CONV_IO_ADDR_KERNEL_0_1_DATA);
    return Data;
}

void XConvolution2d_Set_kernel_0_2(XConvolution2d *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConvolution2d_WriteReg(InstancePtr->Conv_io_BaseAddress, XCONVOLUTION2D_CONV_IO_ADDR_KERNEL_0_2_DATA, Data);
}

u32 XConvolution2d_Get_kernel_0_2(XConvolution2d *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConvolution2d_ReadReg(InstancePtr->Conv_io_BaseAddress, XCONVOLUTION2D_CONV_IO_ADDR_KERNEL_0_2_DATA);
    return Data;
}

void XConvolution2d_Set_kernel_1_0(XConvolution2d *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConvolution2d_WriteReg(InstancePtr->Conv_io_BaseAddress, XCONVOLUTION2D_CONV_IO_ADDR_KERNEL_1_0_DATA, Data);
}

u32 XConvolution2d_Get_kernel_1_0(XConvolution2d *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConvolution2d_ReadReg(InstancePtr->Conv_io_BaseAddress, XCONVOLUTION2D_CONV_IO_ADDR_KERNEL_1_0_DATA);
    return Data;
}

void XConvolution2d_Set_kernel_1_1(XConvolution2d *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConvolution2d_WriteReg(InstancePtr->Conv_io_BaseAddress, XCONVOLUTION2D_CONV_IO_ADDR_KERNEL_1_1_DATA, Data);
}

u32 XConvolution2d_Get_kernel_1_1(XConvolution2d *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConvolution2d_ReadReg(InstancePtr->Conv_io_BaseAddress, XCONVOLUTION2D_CONV_IO_ADDR_KERNEL_1_1_DATA);
    return Data;
}

void XConvolution2d_Set_kernel_1_2(XConvolution2d *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConvolution2d_WriteReg(InstancePtr->Conv_io_BaseAddress, XCONVOLUTION2D_CONV_IO_ADDR_KERNEL_1_2_DATA, Data);
}

u32 XConvolution2d_Get_kernel_1_2(XConvolution2d *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConvolution2d_ReadReg(InstancePtr->Conv_io_BaseAddress, XCONVOLUTION2D_CONV_IO_ADDR_KERNEL_1_2_DATA);
    return Data;
}

void XConvolution2d_Set_kernel_2_0(XConvolution2d *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConvolution2d_WriteReg(InstancePtr->Conv_io_BaseAddress, XCONVOLUTION2D_CONV_IO_ADDR_KERNEL_2_0_DATA, Data);
}

u32 XConvolution2d_Get_kernel_2_0(XConvolution2d *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConvolution2d_ReadReg(InstancePtr->Conv_io_BaseAddress, XCONVOLUTION2D_CONV_IO_ADDR_KERNEL_2_0_DATA);
    return Data;
}

void XConvolution2d_Set_kernel_2_1(XConvolution2d *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConvolution2d_WriteReg(InstancePtr->Conv_io_BaseAddress, XCONVOLUTION2D_CONV_IO_ADDR_KERNEL_2_1_DATA, Data);
}

u32 XConvolution2d_Get_kernel_2_1(XConvolution2d *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConvolution2d_ReadReg(InstancePtr->Conv_io_BaseAddress, XCONVOLUTION2D_CONV_IO_ADDR_KERNEL_2_1_DATA);
    return Data;
}

void XConvolution2d_Set_kernel_2_2(XConvolution2d *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConvolution2d_WriteReg(InstancePtr->Conv_io_BaseAddress, XCONVOLUTION2D_CONV_IO_ADDR_KERNEL_2_2_DATA, Data);
}

u32 XConvolution2d_Get_kernel_2_2(XConvolution2d *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConvolution2d_ReadReg(InstancePtr->Conv_io_BaseAddress, XCONVOLUTION2D_CONV_IO_ADDR_KERNEL_2_2_DATA);
    return Data;
}

u32 XConvolution2d_Get_input_0_BaseAddress(XConvolution2d *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Conv_io_BaseAddress + XCONVOLUTION2D_CONV_IO_ADDR_INPUT_0_BASE);
}

u32 XConvolution2d_Get_input_0_HighAddress(XConvolution2d *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Conv_io_BaseAddress + XCONVOLUTION2D_CONV_IO_ADDR_INPUT_0_HIGH);
}

u32 XConvolution2d_Get_input_0_TotalBytes(XConvolution2d *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XCONVOLUTION2D_CONV_IO_ADDR_INPUT_0_HIGH - XCONVOLUTION2D_CONV_IO_ADDR_INPUT_0_BASE + 1);
}

u32 XConvolution2d_Get_input_0_BitWidth(XConvolution2d *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XCONVOLUTION2D_CONV_IO_WIDTH_INPUT_0;
}

u32 XConvolution2d_Get_input_0_Depth(XConvolution2d *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XCONVOLUTION2D_CONV_IO_DEPTH_INPUT_0;
}

u32 XConvolution2d_Write_input_0_Words(XConvolution2d *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XCONVOLUTION2D_CONV_IO_ADDR_INPUT_0_HIGH - XCONVOLUTION2D_CONV_IO_ADDR_INPUT_0_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Conv_io_BaseAddress + XCONVOLUTION2D_CONV_IO_ADDR_INPUT_0_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XConvolution2d_Read_input_0_Words(XConvolution2d *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XCONVOLUTION2D_CONV_IO_ADDR_INPUT_0_HIGH - XCONVOLUTION2D_CONV_IO_ADDR_INPUT_0_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Conv_io_BaseAddress + XCONVOLUTION2D_CONV_IO_ADDR_INPUT_0_BASE + (offset + i)*4);
    }
    return length;
}

u32 XConvolution2d_Write_input_0_Bytes(XConvolution2d *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XCONVOLUTION2D_CONV_IO_ADDR_INPUT_0_HIGH - XCONVOLUTION2D_CONV_IO_ADDR_INPUT_0_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Conv_io_BaseAddress + XCONVOLUTION2D_CONV_IO_ADDR_INPUT_0_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XConvolution2d_Read_input_0_Bytes(XConvolution2d *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XCONVOLUTION2D_CONV_IO_ADDR_INPUT_0_HIGH - XCONVOLUTION2D_CONV_IO_ADDR_INPUT_0_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Conv_io_BaseAddress + XCONVOLUTION2D_CONV_IO_ADDR_INPUT_0_BASE + offset + i);
    }
    return length;
}

u32 XConvolution2d_Get_input_1_BaseAddress(XConvolution2d *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Conv_io_BaseAddress + XCONVOLUTION2D_CONV_IO_ADDR_INPUT_1_BASE);
}

u32 XConvolution2d_Get_input_1_HighAddress(XConvolution2d *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Conv_io_BaseAddress + XCONVOLUTION2D_CONV_IO_ADDR_INPUT_1_HIGH);
}

u32 XConvolution2d_Get_input_1_TotalBytes(XConvolution2d *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XCONVOLUTION2D_CONV_IO_ADDR_INPUT_1_HIGH - XCONVOLUTION2D_CONV_IO_ADDR_INPUT_1_BASE + 1);
}

u32 XConvolution2d_Get_input_1_BitWidth(XConvolution2d *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XCONVOLUTION2D_CONV_IO_WIDTH_INPUT_1;
}

u32 XConvolution2d_Get_input_1_Depth(XConvolution2d *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XCONVOLUTION2D_CONV_IO_DEPTH_INPUT_1;
}

u32 XConvolution2d_Write_input_1_Words(XConvolution2d *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XCONVOLUTION2D_CONV_IO_ADDR_INPUT_1_HIGH - XCONVOLUTION2D_CONV_IO_ADDR_INPUT_1_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Conv_io_BaseAddress + XCONVOLUTION2D_CONV_IO_ADDR_INPUT_1_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XConvolution2d_Read_input_1_Words(XConvolution2d *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XCONVOLUTION2D_CONV_IO_ADDR_INPUT_1_HIGH - XCONVOLUTION2D_CONV_IO_ADDR_INPUT_1_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Conv_io_BaseAddress + XCONVOLUTION2D_CONV_IO_ADDR_INPUT_1_BASE + (offset + i)*4);
    }
    return length;
}

u32 XConvolution2d_Write_input_1_Bytes(XConvolution2d *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XCONVOLUTION2D_CONV_IO_ADDR_INPUT_1_HIGH - XCONVOLUTION2D_CONV_IO_ADDR_INPUT_1_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Conv_io_BaseAddress + XCONVOLUTION2D_CONV_IO_ADDR_INPUT_1_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XConvolution2d_Read_input_1_Bytes(XConvolution2d *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XCONVOLUTION2D_CONV_IO_ADDR_INPUT_1_HIGH - XCONVOLUTION2D_CONV_IO_ADDR_INPUT_1_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Conv_io_BaseAddress + XCONVOLUTION2D_CONV_IO_ADDR_INPUT_1_BASE + offset + i);
    }
    return length;
}

u32 XConvolution2d_Get_input_2_BaseAddress(XConvolution2d *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Conv_io_BaseAddress + XCONVOLUTION2D_CONV_IO_ADDR_INPUT_2_BASE);
}

u32 XConvolution2d_Get_input_2_HighAddress(XConvolution2d *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Conv_io_BaseAddress + XCONVOLUTION2D_CONV_IO_ADDR_INPUT_2_HIGH);
}

u32 XConvolution2d_Get_input_2_TotalBytes(XConvolution2d *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XCONVOLUTION2D_CONV_IO_ADDR_INPUT_2_HIGH - XCONVOLUTION2D_CONV_IO_ADDR_INPUT_2_BASE + 1);
}

u32 XConvolution2d_Get_input_2_BitWidth(XConvolution2d *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XCONVOLUTION2D_CONV_IO_WIDTH_INPUT_2;
}

u32 XConvolution2d_Get_input_2_Depth(XConvolution2d *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XCONVOLUTION2D_CONV_IO_DEPTH_INPUT_2;
}

u32 XConvolution2d_Write_input_2_Words(XConvolution2d *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XCONVOLUTION2D_CONV_IO_ADDR_INPUT_2_HIGH - XCONVOLUTION2D_CONV_IO_ADDR_INPUT_2_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Conv_io_BaseAddress + XCONVOLUTION2D_CONV_IO_ADDR_INPUT_2_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XConvolution2d_Read_input_2_Words(XConvolution2d *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XCONVOLUTION2D_CONV_IO_ADDR_INPUT_2_HIGH - XCONVOLUTION2D_CONV_IO_ADDR_INPUT_2_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Conv_io_BaseAddress + XCONVOLUTION2D_CONV_IO_ADDR_INPUT_2_BASE + (offset + i)*4);
    }
    return length;
}

u32 XConvolution2d_Write_input_2_Bytes(XConvolution2d *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XCONVOLUTION2D_CONV_IO_ADDR_INPUT_2_HIGH - XCONVOLUTION2D_CONV_IO_ADDR_INPUT_2_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Conv_io_BaseAddress + XCONVOLUTION2D_CONV_IO_ADDR_INPUT_2_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XConvolution2d_Read_input_2_Bytes(XConvolution2d *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XCONVOLUTION2D_CONV_IO_ADDR_INPUT_2_HIGH - XCONVOLUTION2D_CONV_IO_ADDR_INPUT_2_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Conv_io_BaseAddress + XCONVOLUTION2D_CONV_IO_ADDR_INPUT_2_BASE + offset + i);
    }
    return length;
}

u32 XConvolution2d_Get_output_r_BaseAddress(XConvolution2d *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Conv_io_BaseAddress + XCONVOLUTION2D_CONV_IO_ADDR_OUTPUT_R_BASE);
}

u32 XConvolution2d_Get_output_r_HighAddress(XConvolution2d *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Conv_io_BaseAddress + XCONVOLUTION2D_CONV_IO_ADDR_OUTPUT_R_HIGH);
}

u32 XConvolution2d_Get_output_r_TotalBytes(XConvolution2d *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XCONVOLUTION2D_CONV_IO_ADDR_OUTPUT_R_HIGH - XCONVOLUTION2D_CONV_IO_ADDR_OUTPUT_R_BASE + 1);
}

u32 XConvolution2d_Get_output_r_BitWidth(XConvolution2d *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XCONVOLUTION2D_CONV_IO_WIDTH_OUTPUT_R;
}

u32 XConvolution2d_Get_output_r_Depth(XConvolution2d *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XCONVOLUTION2D_CONV_IO_DEPTH_OUTPUT_R;
}

u32 XConvolution2d_Write_output_r_Words(XConvolution2d *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XCONVOLUTION2D_CONV_IO_ADDR_OUTPUT_R_HIGH - XCONVOLUTION2D_CONV_IO_ADDR_OUTPUT_R_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Conv_io_BaseAddress + XCONVOLUTION2D_CONV_IO_ADDR_OUTPUT_R_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XConvolution2d_Read_output_r_Words(XConvolution2d *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XCONVOLUTION2D_CONV_IO_ADDR_OUTPUT_R_HIGH - XCONVOLUTION2D_CONV_IO_ADDR_OUTPUT_R_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Conv_io_BaseAddress + XCONVOLUTION2D_CONV_IO_ADDR_OUTPUT_R_BASE + (offset + i)*4);
    }
    return length;
}

u32 XConvolution2d_Write_output_r_Bytes(XConvolution2d *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XCONVOLUTION2D_CONV_IO_ADDR_OUTPUT_R_HIGH - XCONVOLUTION2D_CONV_IO_ADDR_OUTPUT_R_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Conv_io_BaseAddress + XCONVOLUTION2D_CONV_IO_ADDR_OUTPUT_R_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XConvolution2d_Read_output_r_Bytes(XConvolution2d *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XCONVOLUTION2D_CONV_IO_ADDR_OUTPUT_R_HIGH - XCONVOLUTION2D_CONV_IO_ADDR_OUTPUT_R_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Conv_io_BaseAddress + XCONVOLUTION2D_CONV_IO_ADDR_OUTPUT_R_BASE + offset + i);
    }
    return length;
}

void XConvolution2d_InterruptGlobalEnable(XConvolution2d *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConvolution2d_WriteReg(InstancePtr->Conv_io_BaseAddress, XCONVOLUTION2D_CONV_IO_ADDR_GIE, 1);
}

void XConvolution2d_InterruptGlobalDisable(XConvolution2d *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConvolution2d_WriteReg(InstancePtr->Conv_io_BaseAddress, XCONVOLUTION2D_CONV_IO_ADDR_GIE, 0);
}

void XConvolution2d_InterruptEnable(XConvolution2d *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XConvolution2d_ReadReg(InstancePtr->Conv_io_BaseAddress, XCONVOLUTION2D_CONV_IO_ADDR_IER);
    XConvolution2d_WriteReg(InstancePtr->Conv_io_BaseAddress, XCONVOLUTION2D_CONV_IO_ADDR_IER, Register | Mask);
}

void XConvolution2d_InterruptDisable(XConvolution2d *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XConvolution2d_ReadReg(InstancePtr->Conv_io_BaseAddress, XCONVOLUTION2D_CONV_IO_ADDR_IER);
    XConvolution2d_WriteReg(InstancePtr->Conv_io_BaseAddress, XCONVOLUTION2D_CONV_IO_ADDR_IER, Register & (~Mask));
}

void XConvolution2d_InterruptClear(XConvolution2d *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConvolution2d_WriteReg(InstancePtr->Conv_io_BaseAddress, XCONVOLUTION2D_CONV_IO_ADDR_ISR, Mask);
}

u32 XConvolution2d_InterruptGetEnabled(XConvolution2d *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XConvolution2d_ReadReg(InstancePtr->Conv_io_BaseAddress, XCONVOLUTION2D_CONV_IO_ADDR_IER);
}

u32 XConvolution2d_InterruptGetStatus(XConvolution2d *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XConvolution2d_ReadReg(InstancePtr->Conv_io_BaseAddress, XCONVOLUTION2D_CONV_IO_ADDR_ISR);
}

