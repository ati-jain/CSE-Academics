`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:00:58 08/26/2022 
// Design Name: 
// Module Name:    Ripple64bit 
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
module Ripple64bit(
    input [63:0] a,
    input [63:0] b,
    input cin,
    output [63:0] s,
    output cout
    );
			wire ctemp;

	 //cascaded 2 32-bit RCAs using wire ctemp
    Ripple32bit r1(a[31:0], b[31:0], cin, s[31:0], ctemp);
    Ripple32bit r2(a[63:32], b[63:32], ctemp, s[63:32], cout);

endmodule
