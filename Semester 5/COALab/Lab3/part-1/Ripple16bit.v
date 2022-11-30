`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    12:42:16 08/26/2022 
// Design Name: 
// Module Name:    Ripple16bit 
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
module Ripple16bit(
    input [15:0] a,
    input [15:0] b,
    input cin,
    output [15:0] s,
    output cout
    );
			wire ctemp;
	 //cascaded 2 8-bit RCAs using carry wire
    Ripple8bit r1(a[7:0], b[7:0], cin, s[7:0], ctemp);
    Ripple8bit r2(a[15:8], b[15:8], ctemp, s[15:8], cout);

endmodule
