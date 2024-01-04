`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    02:00:11 09/14/2022 
// Design Name: 
// Module Name:    DFF 
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
module DFF(input [3:0] D, input clk, input rst, output reg [3:0] Q);
	
	always @(posedge clk or posedge rst)
	begin
		if(rst)
			Q <= 4'd0;
		else
			Q <= D;
	end
endmodule
