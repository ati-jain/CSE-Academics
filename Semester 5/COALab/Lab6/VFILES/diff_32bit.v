`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:33:50 10/21/2022 
// Design Name: 
// Module Name:    diff_32bit 
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
module diff_check(
    input wire [31:0] in,
    output reg [31:0] out
  );
  	integer i;
  	always @* begin
    	out = 32'd32; // default value if 'in' is all 0's
    	for (i=31; i>=0; i=i-1)
        	if (in[i]) out = i;
  	end
endmodule

module diff_32bit(
	// here A is rs^rt
	// the decoded output will be equal to A^(A & A-1)
	// out = encoded answer of the decoded output
	input [31:0] A,
	input [31:0] B,
	output wire[31:0] LSB
);
	wire[31:0] w;
	assign w = A^B;

	diff_check p(w, LSB);

endmodule