`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    12:26:29 10/26/2022 
// Design Name: 
// Module Name:    mux_2x1 
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
module mux_2x1(
    input [4:0] in1,
    input [4:0] in2,
    input signal,
    output reg [4:0] out
    );
    
    always @(*)
    begin
        case(signal)
            1'b0:
            begin
                out = in1;
            end
            1'b1:
            begin
                out = in2;
            end
            default
            begin
                out = 32'b0;
            end
			endcase
    end
endmodule
