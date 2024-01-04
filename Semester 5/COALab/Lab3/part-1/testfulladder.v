`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   13:17:57 08/26/2022
// Design Name:   FullAdder
// Module Name:   /mnt/Data/IITKGP/Semester_5/COA_Lab/Lab3/Verilog Demo/ISE Project/RippleCarryAdder/testfulladder.v
// Project Name:  RippleCarryAdder
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: FullAdder
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module testfulladder;

	// Inputs
	reg a;
	reg b;
	reg cin;

	// Outputs
	wire s;
	wire cout;

	// Instantiate the Unit Under Test (UUT)
	FullAdder uut (
		.a(a), 
		.b(b), 
		.cin(cin), 
		.s(s), 
		.cout(cout)
	);

	initial begin
		$monitor ("a = %d, b = %d, cin = %d, s = %d, cout = %d", a, b, cin, s, cout);
		// Initialize Inputs
		a = 0; b = 0; cin = 0;
		#100;
		a = 0; b = 0; cin = 1;
		#100;
		a = 0; b = 1; cin = 0;
		#100;
		a = 0; b = 1; cin = 1;
		#100;
		a = 1; b = 0; cin = 0;
		#100;
		a = 1; b = 0; cin = 1;
		#100;
		a = 1; b = 1; cin = 0;
		#100;
		a = 1; b = 1; cin = 1;
	end
      
endmodule

