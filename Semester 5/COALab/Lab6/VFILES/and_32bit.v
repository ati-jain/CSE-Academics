`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:24:04 10/21/2022 
// Design Name: 
// Module Name:    and_32bit 
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
module and_32bit(
	input [31:0] A,
	input [31:0] B,
	output [31:0] out
    );
	
	and(out[0], A[0], B[0]);
	and(out[1], A[1], B[1]);
	and(out[2], A[2], B[2]);
	and(out[3], A[3], B[3]);
	and(out[4], A[4], B[4]);
	and(out[5], A[5], B[5]);
	and(out[6], A[6], B[6]);
	and(out[7], A[7], B[7]);
	and(out[8], A[8], B[8]);
	and(out[9], A[9], B[9]);
	and(out[10], A[10], B[10]);
	and(out[11], A[11], B[11]);
	and(out[12], A[12], B[12]);
	and(out[13], A[13], B[13]);
	and(out[14], A[14], B[14]);
	and(out[15], A[15], B[15]);
	and(out[16], A[16], B[16]);
	and(out[17], A[17], B[17]);
	and(out[18], A[18], B[18]);
	and(out[19], A[19], B[19]);
	and(out[20], A[20], B[20]);
	and(out[21], A[21], B[21]);
	and(out[22], A[22], B[22]);
	and(out[23], A[23], B[23]);
	and(out[24], A[24], B[24]);
	and(out[25], A[25], B[25]);
	and(out[26], A[26], B[26]);
	and(out[27], A[27], B[27]);
	and(out[28], A[28], B[28]);
	and(out[29], A[29], B[29]);
	and(out[30], A[30], B[30]);
	and(out[31], A[31], B[31]);

endmodule
