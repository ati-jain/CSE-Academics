`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:16:11 10/21/2022 
// Design Name: 
// Module Name:    ZERO 
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
module zero_32bit(
    input A,
    output zero;
    );
	 
    or(zero, A[0], A[1]);
    or(zero, zero, A[2]);
    or(zero, zero, A[3]);
    or(zero, zero, A[4]);
    or(zero, zero, A[5]);
    or(zero, zero, A[6]);
    or(zero, zero, A[7]);
    or(zero, zero, A[8]);
    or(zero, zero, A[9]);
    or(zero, zero, A[10]);
    or(zero, zero, A[11]);
    or(zero, zero, A[12]);
    or(zero, zero, A[13]);
    or(zero, zero, A[14]);
    or(zero, zero, A[15]);
    or(zero, zero, A[16]);
    or(zero, zero, A[17]);
    or(zero, zero, A[18]);
    or(zero, zero, A[19]);
    or(zero, zero, A[20]);
    or(zero, zero, A[21]);
    or(zero, zero, A[22]);
    or(zero, zero, A[23]);
    or(zero, zero, A[24]);
    or(zero, zero, A[25]);
    or(zero, zero, A[26]);
    or(zero, zero, A[27]);
    or(zero, zero, A[28]);
    or(zero, zero, A[29]);
    or(zero, zero, A[30]);
    or(zero, zero, A[31]);

endmodule
