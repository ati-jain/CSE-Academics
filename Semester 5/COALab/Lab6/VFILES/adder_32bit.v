`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:06:25 10/21/2022 
// Design Name: 
// Module Name:    adder32bits 
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
module adder_32bit(
    input [31:0] a,
    input [31:0] b,
    output [31:0] s,
	 output c_out
    );
	wire c_temp, P, G, P1, G1, cin;
	assign cin = 0;
	CLA_16bit_LCU c1(a[15:0], b[15:0], cin, s[15:0], c_temp, P, G);
	CLA_16bit_LCU c2(a[31:16], b[31:16], c_temp, s[31:16], c_out, P1, G1);

endmodule
