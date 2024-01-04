`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   22:50:55 08/30/2022
// Design Name:   CLA16bitRipple
// Module Name:   /mnt/Data/IITKGP/Semester 5/COA_Lab/Lab3/Verilog Demo/ISE Project/LookaheadCarryAdder/LCA/TestCLA16bitRipple.v
// Project Name:  LCA
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: CLA16bitRipple
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module TestCLA16bitRipple;

	// Inputs
	reg [15:0] A;
	reg [15:0] B;
	reg cin;

	// Outputs
	wire [15:0] sum;
	wire cout;

	// Instantiate the Unit Under Test (UUT)
	CLA16bitRipple uut (
		.A(A), 
		.B(B), 
		.cin(cin), 
		.sum(sum), 
		.cout(cout)
	);

	initial begin
		$monitor("A = %d, B = %d, cin = %d, sum = %d, cout = %d", A, B, cin, sum, cout);
		// Initialize Inputs
		// general case
		A = 16'd3; B = 16'd5; cin = 0;
		#100;
		A = 16'd3; B = 16'd5; cin = 1;
		#100;

		// corner case
		A = 16'd16384; B = 16'd16384; cin = 0;
		#100;
		A = 16'd16384; B = 16'd16384; cin = 1;
		#100;
		A = 16'd32767; B = 16'd32768; cin = 0;
		#100;
		A = 16'd32767; B = 16'd32768; cin = 1;
		#100;
		A = 16'd25000; B = 16'd40535; cin = 0;
		#100;
		A = 16'd25000; B = 16'd40535; cin = 1;
	end
      
endmodule

