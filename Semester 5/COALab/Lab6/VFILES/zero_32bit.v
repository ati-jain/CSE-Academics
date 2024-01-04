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
    input [31:0] A,
    output zero
    );
	 
	 assign zero = (A == 32'b0) ? 1'b1 : 1'b0;
	 
endmodule
