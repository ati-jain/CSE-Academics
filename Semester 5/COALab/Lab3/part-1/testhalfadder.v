`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   13:22:38 08/26/2022
// Design Name:   HalfAdder
// Module Name:   /mnt/Data/IITKGP/Semester_5/COA_Lab/Lab3/Verilog Demo/ISE Project/RippleCarryAdder/testhalfadder.v
// Project Name:  RippleCarryAdder
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: HalfAdder
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module testhalfadder;

	// Inputs
	reg a;
	reg b;

	// Outputs
	wire s;
	wire cout;

	// Instantiate the Unit Under Test (UUT)
	HalfAdder uut (
		.a(a), 
		.b(b), 
		.s(s), 
		.cout(cout)
	);

	initial begin
		$monitor ("a = %d, b = %d, s = %d, cout = %d", a, b, s, cout);
		a = 0; b = 0;
		#100;
		a = 0; b = 1;
		#100;
		a = 1; b = 0;
		#100;
		a = 1; b = 1;
	end
      
endmodule

