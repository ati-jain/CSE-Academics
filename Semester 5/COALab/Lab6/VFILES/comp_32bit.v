`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:28:49 10/21/2022 
// Design Name: 
// Module Name:    comp_32bit 
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
module comp_32bit(input [31:0] A,
	output [31:0] out
    );
	 wire [31:0] inv;
	 wire one;
    assign one = 1;

	 xor x0(inv[0], A[0], one);
    xor x1(inv[1], A[1], one);
    xor x2(inv[2], A[2], one);
    xor x3(inv[3], A[3], one);
    xor x4(inv[4], A[4], one);
    xor x5(inv[5], A[5], one);
    xor x6(inv[6], A[6], one);
    xor x7(inv[7], A[7], one);
    xor x8(inv[8], A[8], one);
    xor x9(inv[9], A[9], one);
    xor x10(inv[10], A[10], one);
    xor x11(inv[11], A[11], one);
    xor x12(inv[12], A[12], one);
    xor x13(inv[13], A[13], one);
    xor x14(inv[14], A[14], one);
    xor x15(inv[15], A[15], one);
    xor x16(inv[16], A[16], one);
    xor x17(inv[17], A[17], one);
    xor x18(inv[18], A[18], one);
    xor x19(inv[19], A[19], one);
    xor x20(inv[20], A[20], one);
    xor x21(inv[21], A[21], one);
    xor x22(inv[22], A[22], one);
    xor x23(inv[23], A[23], one);
    xor x24(inv[24], A[24], one);
    xor x25(inv[25], A[25], one);
    xor x26(inv[26], A[26], one);
    xor x27(inv[27], A[27], one);
    xor x28(inv[28], A[28], one);
    xor x29(inv[29], A[29], one);
    xor x30(inv[30], A[30], one);
    xor x31(inv[31], A[31], one);
	 
	 wire [31:0] ON;
	 wire c;
	 assign ON = 1;
	 
	 adder_32bit add(inv, ON, out, c);
	
endmodule
