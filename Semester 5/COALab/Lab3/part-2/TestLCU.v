`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   23:29:53 08/30/2022
// Design Name:   LookaheadCarryUnit
// Module Name:   /mnt/Data/IITKGP/Semester 5/COA_Lab/Lab3/Verilog Demo/ISE Project/LookaheadCarryAdder/LCA/TestLCU.v
// Project Name:  LCA
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: LookaheadCarryUnit
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module TestLCU;

	// Inputs
	reg cin;
	reg [3:0] P;
	reg [3:0] G;

	// Outputs
	wire [4:1] C;
	wire Pout;
	wire Gout;

	// Instantiate the Unit Under Test (UUT)
	LookaheadCarryUnit uut (
		.cin(cin), 
		.P(P), 
		.G(G), 
		.C(C), 
		.Pout(Pout), 
		.Gout(Gout)
	);

	initial begin
		// Initialize Inputs
		cin = 0;
		P = 0;
		G = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here

	end
      
endmodule

