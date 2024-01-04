`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    01:58:48 09/14/2022 
// Design Name: 
// Module Name:    addbyone 
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
module addbyone(input [3:0] A, output [3:0] sum);

	
   wire [3:0] B; 
	wire w1, w2, w3, cout;
	
	assign B = 4'b0001;

	FullAdder u1(A[0], B[0], 1'b0, sum[0], w1);
	FullAdder u2(A[1], B[1], w1, sum[1], w2);
	FullAdder u3(A[2], B[2], w2, sum[2], w3);
	FullAdder u4(A[3], B[3], w3, sum[3], cout); 
endmodule
