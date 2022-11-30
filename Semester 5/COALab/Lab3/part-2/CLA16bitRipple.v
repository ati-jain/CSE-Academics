`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    22:49:49 08/30/2022 
// Design Name: 
// Module Name:    CLA16bitRipple 
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
module CLA16bitRipple(
    input [15:0] A,
    input [15:0] B,
    input cin,
    output [15:0] sum,
    output cout
    );
	wire [2:0] c; //3 wires for rippling the carries
	
	// 16 bit adder by cascading 4 4-bit CLAs and rippling the inernal carry
	CLA4bit c1(A[3:0], B[3:0], cin, sum[3:0], c[0]);
	CLA4bit c2(A[7:4], B[7:4], c[0], sum[7:4], c[1]);
	CLA4bit c3(A[11:8], B[11:8], c[1], sum[11:8], c[2]);
	CLA4bit c4(A[15:12], B[15:12], c[2], sum[15:12], cout);

endmodule
