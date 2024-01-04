`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    12:12:27 08/26/2022 
// Design Name: 
// Module Name:    HalfAdder 
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
module HalfAdder(
    input a,
    input b,
    output s,
    output cout
    );

	xor g1(s, a, b);
	and g2(cout, a, b);

endmodule
