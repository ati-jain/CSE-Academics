`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   04:16:21 10/23/2022
// Design Name:   KGP_RISC
// Module Name:   /home/suneetha/Desktop/miniRISC/branchcontroller_test.v
// Project Name:  miniRISC
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: KGP_RISC
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module branchcontroller_test;
   
	// Inputs
	reg [5:0] opcode;
	reg zero;
	reg sign;
	reg carry;
	// Outputs
	wire [1:0] PCSrc;

	// Instantiate the Unit Under Test (UUT)
	branch_controller uut (
		.opcode(opcode),
		.zero(zero),
		.sign(sign),
		.carry(carry),
		.PCSrc(PCSrc),
	);

	initial begin
		// Initialize Inputs
      $monitor ("op = %b, zero = %b, sign = %b, carry = %b, PCSRC = %b", opcode, zero, sign, carry, PCSrc);
		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
      opcode = 100010;
		sign = 1;
		#10;
		opcode = 100011;
		zero = 1;
		#10;
		opcode = 100100;
		zero = 0;
		#10;
		opcode = 100110;
		carry = 1;
		#10;
		opcode = 100111;
		carry = 0;
	end
      
endmodule

