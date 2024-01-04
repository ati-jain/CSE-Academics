`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:11:21 10/21/2022 
// Design Name: 
// Module Name:    CLA_16bit_LCU 
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
module CLA_16bit_LCU(
    input [15:0] A,
    input [15:0] B,
    input cin,
    output [15:0] sum,
    output cout,
	 output Pout,
	 output Gout
    );
	 
	wire [4:1] C; // wires ConneCting carries from the LCU to the 4-bit CLAs as cin
	wire [3:0] P, G; // wires connecting block propagate and block generate from 4-bit CLAs to the LCU
	 
	// 16 bit adder by using 4 4-bit CLAs and a LCU (Lookahead Carry Unit)
	CLA4bitAugmented c1(A[3:0], B[3:0], cin, sum[3:0], P[0], G[0]);
	CLA4bitAugmented c2(A[7:4], B[7:4], C[1], sum[7:4], P[1], G[1]);
	CLA4bitAugmented c3(A[11:8], B[11:8], C[2], sum[11:8], P[2], G[2]);
	CLA4bitAugmented c4(A[15:12], B[15:12], C[3], sum[15:12], P[3], G[3]);
	
	LookaheadCarryUnit lcu(cin, P, G, C, Pout, Gout);

	assign cout = C[4];

endmodule
