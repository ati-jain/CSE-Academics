`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:36:11 10/26/2022 
// Design Name: 
// Module Name:    ProgramCounter 
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
module ProgramCounter(input [31:0] PC_in,
	 input clk,
	 input reset,
	 output reg [31:0] PC_out
    );
      always @(negedge clk or posedge reset)
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
