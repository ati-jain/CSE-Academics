`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    12:21:59 10/26/2022 
// Design Name: 
// Module Name:    mux_3x1 
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
module mux_3x1(
    input [31:0] in1,
    input [31:0] in2,
    input [31:0] in3,
    input [1:0] signal,
    output reg [31:0] out
    );
    
    always @(*)
    begin
        case(signal)
            2'b00:
            begin
                out = in1;
            end
            2'b01:
            begin
                out = in2;
            end
            2'b10:
            begin
                out = in3;
            end
            default
            begin
                out = 32'b0;
            end
		endcase
	 end
endmodule
