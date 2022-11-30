`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:15:26 09/14/2022 
// Design Name: 
// Module Name:    clkdiv 
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
module clkdiv(
	input clock_in, // input clock on FPGA
	output reg clock_out); // output clock after dividing the input clock by divisor
	reg[27:0] counter=-28'd1;
	integer DIVISOR = 28'd400000;
	
	always @(posedge clock_in)
	begin
		counter <= counter + 28'd1;
		if(counter > DIVISOR)
			counter <= 28'd0;
		clock_out <= (counter < DIVISOR/2) ? 1'b1 : 1'b0;
	end
endmodule

