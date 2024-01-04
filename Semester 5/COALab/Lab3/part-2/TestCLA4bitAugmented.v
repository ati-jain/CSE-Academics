`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   23:31:13 08/30/2022
// Design Name:   CLA4bitAugmented
// Module Name:   /mnt/Data/IITKGP/Semester 5/COA_Lab/Lab3/Verilog Demo/ISE Project/LookaheadCarryAdder/LCA/TestCLA4bitAugmented.v
// Project Name:  LCA
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: CLA4bitAugmented
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module TestCLA4bitAugmented;

	// Inputs
	reg [3:0] A;
	reg [3:0] B;
	reg cin;

	// Outputs
	wire [3:0] sum;
	wire Pout;
	wire Gout;

	// Instantiate the Unit Under Test (UUT)
	CLA4bitAugmented uut (
		.A(A), 
		.B(B), 
		.cin(cin), 
		.sum(sum), 
		.Pout(Pout), 
		.Gout(Gout)
	);

	initial begin
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

