`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:51:29 10/25/2022 
// Design Name: 
// Module Name:    prog_counter 
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
module prog_counter(
    input [31:0] PC_in,
	 input clk,
	 input reset,
	 output reg [31:0] PC_out
    );
      always @(posedge clk or posedge reset)
	   begin
		      if(reset == 1)
			   begin
				      PC_out = 32'd0; // reset condition -> 2nd Address on the Instruction Fetch Memory
			   end
				
		      else
			   begin
				      PC_out = PC_in; // set next value of pc
			   end
	   end
endmodule
