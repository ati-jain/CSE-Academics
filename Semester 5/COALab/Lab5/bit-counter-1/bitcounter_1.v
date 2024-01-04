`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    02:13:23 09/14/2022 
// Design Name: 
// Module Name:    bitcounter_1 
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
module bitcounter_1(input clk, input reset, output reg [3:0] counter);
	 wire sclk;
	 clkDiv c1(clk, sclk);

	always @(posedge sclk or posedge reset)
		begin
			if(reset)
			 counter <= 4'b0000;
			else
			 counter <= counter + 4'b0001;
		end
endmodule
