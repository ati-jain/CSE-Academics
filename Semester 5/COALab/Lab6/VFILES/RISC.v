`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:33:21 10/26/2022 
// Design Name: 
// Module Name:    RISC 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module RISC(
    input clk,
    input rst,
	 output [31:0] Return
    );

    wire [31:0] instr;

    wire MemRead, MemWirte, RegDst, RegWrite;
	 wire zero, sign, carry;
    wire [1:0] MemToReg, ALUSrc, PCSrc;
    wire [3:0] ALUOp;
    wire [5:0] opCode, funCode;
    wire [4:0] reg1, reg2, reg_write_addr, shamt, ra;
    wire [15:0] add, imm;
	 wire [31:0] data1,data2;
	 wire [31:0] B;
	 wire [31:0] addSE, shamtSE, immSE;
	 wire [31:0] Output, Address, ReadData, PC_in, readAddress, nextAddress, write_data;

	 //assign A = 0;
	 //assign B = 0;
	 assign ra = 5'b11111;
    assign opCode = instr[31:26];
	 assign funCode = instr[10:5];
    assign reg1 = instr[25:21];
    assign reg2 = instr[20:16];
    assign shamt = instr[15:11];
    assign add = instr[15:0];
    assign imm = instr[15:0];
	 assign Address = Output;

	 next_addr add4(readAddress, nextAddress);

    Controller cntrlr(opCode, funCode, MemToReg, ALUOp, ALUSrc, RegDst, RegWrite, MemRead, MemWrite);

    register_file RegFile(clk, rst, RegWrite, reg1, reg2, reg_write_addr, write_data, data1, data2);

	 //assign A = data1;

	 sign_extender_16bit se1(add, addSE);
	 sign_extender_5bit se2(shamt, shamtSE);
	 sign_extender_16bit se3(imm, immSE);

	 mux_3x1 Src(data2, shamtSE, immSE, ALUSrc, B);

	 BranchControl BrnCntrl(opCode, zero, sign, carry, PCSrc);

	 ALU alu(data1, B, ALUOp, Output, zero, sign, carry);

	 ProgramCounter pc(PC_in, clk, rst, readAddress); 

	 datamemory DM(Address, clk, rst, MemRead, MemWrite, data2, ReadData);

	 InstrMem IM(readAddress, clk, reset, instr);

    mux_3x1 branch(nextAddress, data1, addSE, PCSrc, PC_in);

	 mux_3x1 m3(nextAddress, ReadData, Output, MemToReg, write_data);

	 mux_2x1 write(reg2, ra, RegDst, reg_write_addr);

	 assign Return = write_data;
	 always @(posedge clk)
	 begin
		$display("instr = %b, PC_in = %b", instr, addSE);
	 end
endmodule
