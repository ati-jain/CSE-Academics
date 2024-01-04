`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:02:22 10/26/2022 
// Design Name: 
// Module Name:    next_addr 
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
module next_addr(
	 input [31:0] address,
	 output [31:0] nextAddress
    );

	 wire [31:0] one;
	 wire c;
	 assign one = 32'b1;
	 adder_32bit adder(address, one, nextAddress, c);

endmodule

//01000000000000010000000000000001,
