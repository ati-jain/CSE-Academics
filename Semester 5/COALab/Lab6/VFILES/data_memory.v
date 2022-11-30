`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    22:44:48 10/25/2022 
// Design Name: 
// Module Name:    data_memory 
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
module data_memory(
    input [31:0] address,
    input clk,
	 input reset,
    input memread,
    input memwrite,
    input [31:0] write_data,
    output [31:0] read_data
    );
	 
	 wire wr_enable;
	 assign wr_enable = (mem_write & (~mem_read));
	 
	 dRAM datamem (
    .clka(~clk), // input clka
    .rsta(reset), // input rsta
    .wea(wr_enable), // input [0 : 0] wea
    .addra(address[9:0]), // input [9 : 0] addra
    .dina(write_data), // input [31 : 0] dina
    .douta(read_data) // output [31 : 0] douta
    );


endmodule
