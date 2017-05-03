//*****************************************************************************
//--ALUSimulator.c
//
//		Author: 		Gary J. Minden
//		Organization:	KU/EECS/EECS 645
//		Date:			2017-04-22 (B70422)
//		Version:		1.0
//		Description:	This is the test standin for a simple ALU simulator
//		Notes:
//
//*****************************************************************************
//

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdarg.h>

#include <stdio.h>

#include "RegisterFile_01.h"
#include "ALUSimulator.h"
#include <math.h>
extern void ALUSimulator( RegisterFile theRegisterFile,
				uint32_t OpCode,
				uint32_t Rs, uint32_t Rt, uint32_t Rd,
				uint32_t ShiftAmt,
				uint32_t FunctionCode,
				uint32_t ImmediateValue,
				uint32_t* Status ) {

	uint32_t RsValue;
	uint32_t RtValue;
	uint32_t RdValue;


	switch(OpCode){
		case 0:{
			if(FunctionCode == 32){
				RegisterFile_Read(theRegisterFile, Rs, &RsValue, Rt, &RtValue);
				RdValue = RsValue + RtValue;
				RegisterFile_Write(theRegisterFile, 1, Rd, RdValue);
			}
			else if(FunctionCode == 0){
				RegisterFile_Read(theRegisterFile, Rs, &RsValue, Rt, &RtValue);
				RdValue = RtValue << ShiftAmt;
				RegisterFile_Write(theRegisterFile, 1, Rd, RdValue);
			}
			else if(FunctionCode == 37){
				RegisterFile_Read(theRegisterFile, Rs, &RsValue, Rt, &RtValue);
				RdValue = RsValue | RtValue;
				RegisterFile_Write(theRegisterFile, 1, Rd, RdValue);
			}
			else if(FunctionCode == 38){
				RegisterFile_Read(theRegisterFile, Rs, &RsValue, Rt, &RtValue);
				RdValue = RsValue ^ RtValue;
				RegisterFile_Write(theRegisterFile, 1, Rd, RdValue);
			}
			else if(FunctionCode == 34){
				RegisterFile_Read(theRegisterFile, Rs, &RsValue, Rt, &RtValue);
				RdValue = RsValue - RtValue;
				RegisterFile_Write(theRegisterFile, 1, Rd, RdValue);
			} else if(FunctionCode == 36){
				
			}
			break;
		}
		case 8:{
			RegisterFile_Read(theRegisterFile, Rs, &RsValue, Rt, &RtValue);
			RsValue = RsValue + (int32_t)(int16_t)ImmediateValue;
			RegisterFile_Write(theRegisterFile, 1, Rt, RsValue);
			break;
		}
		case 9:{
			break;
		}
		case 10:{
			break;
		}
		case 11:{
			break;
		}
	}


	printf( ">>ALU: Opcode: %02X; Rs: %02X; Rt: %02X; Rd: %02X;\n",
				OpCode,
				Rs,
				Rt,
				Rd );

	printf( ">>>>ALU: ShiftAmt: %02X; FunctionCode: %02X; ImmediateValue: %04X;\n",
				ShiftAmt,
				FunctionCode,
				ImmediateValue );

}
