`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    12:51:46 08/26/2022 
// Design Name: 
// Module Name:    Ripple32bit 
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
module Ripple32bit(
    input [31:0] a,
    input [31:0] b,
    input cin,
    output [31:0] s,
    output cout
    );
			 wire ctemp;
	 //cascaded 2 16-bit RCAs using ctemp wire
    Ripple16bit r1(a[15:0], b[15:0], cin, s[15:0], ctemp);
    Ripple16bit r2(a[31:16], b[31:16], ctemp, s[31:16], cout);

endmodule
