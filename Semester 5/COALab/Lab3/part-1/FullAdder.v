`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    12:10:26 08/26/2022 
// Design Name: 
// Module Name:    FullAdder 
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
module FullAdder(
    input a,
    input b,
    input cin,
    output s,
    output cout
    );

		 wire c1,c2,temp;

	 HalfAdder h1(a, b, temp, c1);
    HalfAdder h2(temp, cin, s, c2);
    or gate(cout, c1, c2);
endmodule
