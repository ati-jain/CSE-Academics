`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    01:57:59 09/14/2022 
// Design Name: 
// Module Name:    bitcounter_2 
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
module bitcounter_2(input clk, input reset, output[3:0] counter);

	wire sclk;
	wire [3:0] D;
	
	clkdiv c1(clk, sclk);
	addbyone a1(counter[3:0], D[3:0]);
	DFF d1(D[3:0], sclk, reset, counter[3:0]);

endmodule

