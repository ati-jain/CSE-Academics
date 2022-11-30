`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   16:14:55 10/28/2022
// Design Name:   sign_extender_16bit
// Module Name:   /mnt/Data/IITKGP/Semester 5/COA_Lab/Lab6/RISC/test_se_16bit.v
// Project Name:  RISC
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: sign_extender_16bit
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module test_se_16bit;

	// Inputs
	reg [15:0] in;

	// Outputs
	wire [31:0] out;

	// Instantiate the Unit Under Test (UUT)
	sign_extender_16bit uut (
		.in(in), 
		.out(out)
	);

	initial begin
		// Initialize Inputs
		$monitor("in = %b, out = %b", in, out);
		in = 0;

		// Wait 100 ns for global reset to finish
		#100;
		in = 16'b1;
		#100;
		in = 16'b0000000011111111;
		#100;
		in = 16'b1000000000111111;
        
		// Add stimulus here

	end
      
endmodule

