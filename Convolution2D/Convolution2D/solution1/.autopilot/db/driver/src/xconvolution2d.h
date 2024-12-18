// ==============================================================
// File generated on Wed Dec 18 21:02:53 +0700 2024
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XCONVOLUTION2D_H
#define XCONVOLUTION2D_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xconvolution2d_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Conv_io_BaseAddress;
} XConvolution2d_Config;
#endif

typedef struct {
    u32 Conv_io_BaseAddress;
    u32 IsReady;
} XConvolution2d;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XConvolution2d_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XConvolution2d_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XConvolution2d_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XConvolution2d_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XConvolution2d_Initialize(XConvolution2d *InstancePtr, u16 DeviceId);
XConvolution2d_Config* XConvolution2d_LookupConfig(u16 DeviceId);
int XConvolution2d_CfgInitialize(XConvolution2d *InstancePtr, XConvolution2d_Config *ConfigPtr);
#else
int XConvolution2d_Initialize(XConvolution2d *InstancePtr, const char* InstanceName);
int XConvolution2d_Release(XConvolution2d *InstancePtr);
#endif

void XConvolution2d_Start(XConvolution2d *InstancePtr);
u32 XConvolution2d_IsDone(XConvolution2d *InstancePtr);
u32 XConvolution2d_IsIdle(XConvolution2d *InstancePtr);
u32 XConvolution2d_IsReady(XConvolution2d *InstancePtr);
void XConvolution2d_EnableAutoRestart(XConvolution2d *InstancePtr);
void XConvolution2d_DisableAutoRestart(XConvolution2d *InstancePtr);

void XConvolution2d_Set_kernel_0_0(XConvolution2d *InstancePtr, u32 Data);
u32 XConvolution2d_Get_kernel_0_0(XConvolution2d *InstancePtr);
void XConvolution2d_Set_kernel_0_1(XConvolution2d *InstancePtr, u32 Data);
u32 XConvolution2d_Get_kernel_0_1(XConvolution2d *InstancePtr);
void XConvolution2d_Set_kernel_0_2(XConvolution2d *InstancePtr, u32 Data);
u32 XConvolution2d_Get_kernel_0_2(XConvolution2d *InstancePtr);
void XConvolution2d_Set_kernel_1_0(XConvolution2d *InstancePtr, u32 Data);
u32 XConvolution2d_Get_kernel_1_0(XConvolution2d *InstancePtr);
void XConvolution2d_Set_kernel_1_1(XConvolution2d *InstancePtr, u32 Data);
u32 XConvolution2d_Get_kernel_1_1(XConvolution2d *InstancePtr);
void XConvolution2d_Set_kernel_1_2(XConvolution2d *InstancePtr, u32 Data);
u32 XConvolution2d_Get_kernel_1_2(XConvolution2d *InstancePtr);
void XConvolution2d_Set_kernel_2_0(XConvolution2d *InstancePtr, u32 Data);
u32 XConvolution2d_Get_kernel_2_0(XConvolution2d *InstancePtr);
void XConvolution2d_Set_kernel_2_1(XConvolution2d *InstancePtr, u32 Data);
u32 XConvolution2d_Get_kernel_2_1(XConvolution2d *InstancePtr);
void XConvolution2d_Set_kernel_2_2(XConvolution2d *InstancePtr, u32 Data);
u32 XConvolution2d_Get_kernel_2_2(XConvolution2d *InstancePtr);
u32 XConvolution2d_Get_input_0_BaseAddress(XConvolution2d *InstancePtr);
u32 XConvolution2d_Get_input_0_HighAddress(XConvolution2d *InstancePtr);
u32 XConvolution2d_Get_input_0_TotalBytes(XConvolution2d *InstancePtr);
u32 XConvolution2d_Get_input_0_BitWidth(XConvolution2d *InstancePtr);
u32 XConvolution2d_Get_input_0_Depth(XConvolution2d *InstancePtr);
u32 XConvolution2d_Write_input_0_Words(XConvolution2d *InstancePtr, int offset, int *data, int length);
u32 XConvolution2d_Read_input_0_Words(XConvolution2d *InstancePtr, int offset, int *data, int length);
u32 XConvolution2d_Write_input_0_Bytes(XConvolution2d *InstancePtr, int offset, char *data, int length);
u32 XConvolution2d_Read_input_0_Bytes(XConvolution2d *InstancePtr, int offset, char *data, int length);
u32 XConvolution2d_Get_input_1_BaseAddress(XConvolution2d *InstancePtr);
u32 XConvolution2d_Get_input_1_HighAddress(XConvolution2d *InstancePtr);
u32 XConvolution2d_Get_input_1_TotalBytes(XConvolution2d *InstancePtr);
u32 XConvolution2d_Get_input_1_BitWidth(XConvolution2d *InstancePtr);
u32 XConvolution2d_Get_input_1_Depth(XConvolution2d *InstancePtr);
u32 XConvolution2d_Write_input_1_Words(XConvolution2d *InstancePtr, int offset, int *data, int length);
u32 XConvolution2d_Read_input_1_Words(XConvolution2d *InstancePtr, int offset, int *data, int length);
u32 XConvolution2d_Write_input_1_Bytes(XConvolution2d *InstancePtr, int offset, char *data, int length);
u32 XConvolution2d_Read_input_1_Bytes(XConvolution2d *InstancePtr, int offset, char *data, int length);
u32 XConvolution2d_Get_input_2_BaseAddress(XConvolution2d *InstancePtr);
u32 XConvolution2d_Get_input_2_HighAddress(XConvolution2d *InstancePtr);
u32 XConvolution2d_Get_input_2_TotalBytes(XConvolution2d *InstancePtr);
u32 XConvolution2d_Get_input_2_BitWidth(XConvolution2d *InstancePtr);
u32 XConvolution2d_Get_input_2_Depth(XConvolution2d *InstancePtr);
u32 XConvolution2d_Write_input_2_Words(XConvolution2d *InstancePtr, int offset, int *data, int length);
u32 XConvolution2d_Read_input_2_Words(XConvolution2d *InstancePtr, int offset, int *data, int length);
u32 XConvolution2d_Write_input_2_Bytes(XConvolution2d *InstancePtr, int offset, char *data, int length);
u32 XConvolution2d_Read_input_2_Bytes(XConvolution2d *InstancePtr, int offset, char *data, int length);
u32 XConvolution2d_Get_output_r_BaseAddress(XConvolution2d *InstancePtr);
u32 XConvolution2d_Get_output_r_HighAddress(XConvolution2d *InstancePtr);
u32 XConvolution2d_Get_output_r_TotalBytes(XConvolution2d *InstancePtr);
u32 XConvolution2d_Get_output_r_BitWidth(XConvolution2d *InstancePtr);
u32 XConvolution2d_Get_output_r_Depth(XConvolution2d *InstancePtr);
u32 XConvolution2d_Write_output_r_Words(XConvolution2d *InstancePtr, int offset, int *data, int length);
u32 XConvolution2d_Read_output_r_Words(XConvolution2d *InstancePtr, int offset, int *data, int length);
u32 XConvolution2d_Write_output_r_Bytes(XConvolution2d *InstancePtr, int offset, char *data, int length);
u32 XConvolution2d_Read_output_r_Bytes(XConvolution2d *InstancePtr, int offset, char *data, int length);

void XConvolution2d_InterruptGlobalEnable(XConvolution2d *InstancePtr);
void XConvolution2d_InterruptGlobalDisable(XConvolution2d *InstancePtr);
void XConvolution2d_InterruptEnable(XConvolution2d *InstancePtr, u32 Mask);
void XConvolution2d_InterruptDisable(XConvolution2d *InstancePtr, u32 Mask);
void XConvolution2d_InterruptClear(XConvolution2d *InstancePtr, u32 Mask);
u32 XConvolution2d_InterruptGetEnabled(XConvolution2d *InstancePtr);
u32 XConvolution2d_InterruptGetStatus(XConvolution2d *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
