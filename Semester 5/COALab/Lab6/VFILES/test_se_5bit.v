`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   16:20:59 10/28/2022
// Design Name:   sign_extender_5bit
// Module Name:   /mnt/Data/IITKGP/Semester 5/COA_Lab/Lab6/RISC/test_se_5bit.v
// Project Name:  RISC
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: sign_extender_5bit
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module test_se_5bit;

	// Inputs
	reg [4:0] in;

	// Outputs
	wire [31:0] out;

	// Instantiate the Unit Under Test (UUT)
	sign_extender_5bit uut (
		.in(in), 
		.out(out)
	);

	initial begin
		$monitor("in = %b, out = %b", in, out);
		// Initialize Inputs
		in = 0;

		// Wait 100 ns for global reset to finish
		#100;
		in = 5'b00111;
		#100;
		in = 5'b11111;
		#100;
		in = 5'b10000;
        
		// Add stimulus here

	end
      
endmodule
