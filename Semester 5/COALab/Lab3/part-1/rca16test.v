`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   12:46:01 08/26/2022
// Design Name:   Ripple16bit
// Module Name:   /mnt/Data/IITKGP/Semester_5/COA_Lab/Lab3/Verilog Demo/ISE Project/RippleCarryAdder/rca16test.v
// Project Name:  RippleCarryAdder
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Ripple16bit
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module rca16test;

	// Inputs
	reg [15:0] a;
	reg [15:0] b;
	reg cin;

	// Outputs
	wire [15:0] s;
	wire cout;

	// Instantiate the Unit Under Test (UUT)
	Ripple16bit uut (
		.a(a), 
		.b(b), 
		.cin(cin), 
		.s(s), 
		.cout(cout)
	);

	initial begin
		$monitor ("a = %d, b = %d, cin = %d, s = %d, cout = %d", a, b, cin, s, cout);
		// Initialize Inputs
		//general cases
		a = 16'd164; b = 16'd184; cin = 0;
		#100;
		a = 16'd184; b = 16'd164; cin = 0;
		#100;
		//corner cases
		a = 16'd16384; b = 16'd16384; cin = 0;
		#100;
		a = 16'd16384; b = 16'd16384; cin = 1;
		#100;
		a = 16'd32767; b = 16'd1; cin = 0;
	end
      
endmodule

