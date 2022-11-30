`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:18:53 10/26/2022 
// Design Name: 
// Module Name:    instruction_memory 
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
module instruction_memory(
    input [31:0] pc,
	 input clk,
	 input reset,
	 output [31:0] instruction
    );
	 
	 instrROM your_instance_name (
    .clka(clk), // input clka
    .rsta(reset), // input rsta
    .addra(pc[9:0]), // input [9 : 0] addra
    .douta(instruction) // output [31 : 0] douta
);


endmodule
