// ==============================================================
// File generated on Wed Dec 18 21:02:53 +0700 2024
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xconvolution2d.h"

extern XConvolution2d_Config XConvolution2d_ConfigTable[];

XConvolution2d_Config *XConvolution2d_LookupConfig(u16 DeviceId) {
	XConvolution2d_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XCONVOLUTION2D_NUM_INSTANCES; Index++) {
		if (XConvolution2d_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XConvolution2d_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XConvolution2d_Initialize(XConvolution2d *InstancePtr, u16 DeviceId) {
	XConvolution2d_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XConvolution2d_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XConvolution2d_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

