`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   14:28:25 10/21/2022
// Design Name:   adder32bits
// Module Name:   /mnt/Data/IITKGP/Semester 5/COA_Lab/Lab3/part-1/RISC/test_adder.v
// Project Name:  RISC
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: adder32bits
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module test_adder;

	// Inputs
	reg [31:0] a;
	reg [31:0] b;

	// Outputs
	wire [31:0] s;
	wire c_out;

	// Instantiate the Unit Under Test (UUT)
	adder32bits uut (
		.a(a), 
		.b(b), 
		.s(s), 
		.c_out(c_out)
	);

	initial begin
		// Initialize Inputs
		$monitor ("a = %d, b = %d, s = %d, c_out = %d", a, b, s, c_out);
		a = 32'd100; b = 32'd200;
		// Wait 100 ns for global reset to finish
      #100
		a = 32'd200; b = 32'd100;
		// Add stimulus here

	end
      
endmodule

