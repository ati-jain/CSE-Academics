`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:42:11 10/21/2022 
// Design Name: 
// Module Name:    shll_32bit 
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
module shll_32bit(
	input [31:0] A,
	input [31:0] shft,
	output [31:0] out
    );
	
	assign out = A << shft;

endmodule
