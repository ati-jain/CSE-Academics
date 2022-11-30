`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:39:09 10/26/2022 
// Design Name: 
// Module Name:    InstrMem 
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
module InstrMem(
    input [31:0] pc,
	 input clk,
	 input reset,
	 output [31:0] instruction
    );
	 
	 InstROM InstrMemory (
    .clka(clk), // input clka
    .addra(pc[9:0]), // input [9 : 0] addra
    .douta(instruction) // output [31 : 0] douta
);

endmodule
