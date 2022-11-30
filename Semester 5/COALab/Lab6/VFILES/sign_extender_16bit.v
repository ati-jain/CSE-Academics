`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    12:18:17 10/26/2022 
// Design Name: 
// Module Name:    sign_extender_16bit 
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
module sign_extender_16bit(
    input [15:0] in,
    output [31:0] out
    );

    assign out[15:0] = in[15:0];
    assign out[31:16] = {16{in[15]}};

endmodule
