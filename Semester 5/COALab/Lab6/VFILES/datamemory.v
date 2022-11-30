`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:11:42 10/26/2022 
// Design Name: 
// Module Name:    datamemory 
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
module datamemory(
	 input [31:0] address,
    input clk,
	 input reset,
    input mem_read,
    input mem_write,
    input [31:0] write_data,
    output [31:0] read_data
);

	 dataMem datamem (
    .clka(~clk), // input clka
    //.rsta(reset), // input rsta
	 //.ena(mem_read), // input mem_read
    .wea(mem_write), // input [0 : 0] wea
    .addra(address[9:0]), // input [9 : 0] addra
    .dina(write_data), // input [31 : 0] dina
    .douta(read_data) // output [31 : 0] douta
    );

endmodule
