`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    12:09:01 08/26/2022 
// Design Name: 
// Module Name:    RippleCarryAdder 
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
module Ripple8bit(
    input [7:0] a,
    input [7:0] b,
    input cin,
    output [7:0] s,
    output cout
    );

		 wire [6:0] ctemp;
	 
	FullAdder a1(a[0], b[0], cin, s[0], ctemp[0]);
	FullAdder a2(a[1], b[1], ctemp[0], s[1], ctemp[1]);
	FullAdder a3(a[2], b[2], ctemp[1], s[2], ctemp[2]);
	FullAdder a4(a[3], b[3], ctemp[2], s[3], ctemp[3]);
	FullAdder a5(a[4], b[4], ctemp[3], s[4], ctemp[4]);
	FullAdder a6(a[5], b[5], ctemp[4], s[5], ctemp[5]);
	FullAdder a7(a[6], b[6], ctemp[5], s[6], ctemp[6]);
	FullAdder a8(a[7], b[7], ctemp[6], s[7], cout);
endmodule
