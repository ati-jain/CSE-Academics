`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   00:59:45 08/31/2022
// Design Name:   CLA4bit
// Module Name:   /mnt/Data/IITKGP/Semester 5/COA_Lab/Lab3/Verilog Demo/ISE Project/LookaheadCarryAdder/LCA/TestCLA4bit.v
// Project Name:  LCA
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: CLA4bit
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module TestCLA4bit;

	// Inputs
	reg [3:0] A;
	reg [3:0] B;
	reg cin;

	// Outputs
	wire [3:0] sum;
	wire cout;

	// Instantiate the Unit Under Test (UUT)
	CLA4bit uut (
		.A(A), 
		.B(B), 
		.cin(cin), 
		.sum(sum), 
		.cout(cout)
	);

	initial begin
		$monitor ("A = %d, B = %d, cin = %d, sum = %d, cout = %d", A, B, cin, sum, cout);
		// Initialize Inputs
		// general case
		A = 4'd8; B = 4'd5; cin = 0;
		#100;
		A = 4'd2; B = 4'd3; cin = 0;
		#100;
		A = 4'd2; B = 4'd3; cin = 1;
		#100;

		// corner case
		A = 4'd10; B = 4'd5; cin = 0;
		#100;
		A = 4'd10; B = 4'd5; cin = 1;
		#100;
		A = 4'd8; B = 4'd7; cin = 0;
		#100;
		A = 4'd8; B = 4'd7; cin = 1;
	end
      
endmodule

