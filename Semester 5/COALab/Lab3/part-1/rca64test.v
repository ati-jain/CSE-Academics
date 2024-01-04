`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   13:06:22 08/26/2022
// Design Name:   Ripple64bit
// Module Name:   /mnt/Data/IITKGP/Semester_5/COA_Lab/Lab3/Verilog Demo/ISE Project/RippleCarryAdder/rca64test.v
// Project Name:  RippleCarryAdder
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Ripple64bit
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module rca64test;

	// Inputs
	reg [63:0] a;
	reg [63:0] b;
	reg cin;

	// Outputs
	wire [63:0] s;
	wire cout;

	// Instantiate the Unit Under Test (UUT)
	Ripple64bit uut (
		.a(a), 
		.b(b), 
		.cin(cin), 
		.s(s), 
		.cout(cout)
	);

	initial begin
		$monitor ("a = %d, b = %d, cin = %d, s = %d, cout = %d", a, b, cin, s, cout);
		// Initialize Inputs
		// general cases
		a = 64'd100; b = 64'd100; cin = 0;
		#100;
		a = 64'd102560; b = 64'd1215500; cin = 1;
		#100;
		a = 64'd2563100; b = 64'd1001111; cin = 0;
		#100;
		a = 64'd2663100; b = 64'd65166213100; cin = 0;
		#100;
		a = 64'd2663100; b = 64'd65166213100; cin = 1;
		#100;
	end
      
endmodule

