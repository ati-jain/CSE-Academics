`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   15:46:25 10/28/2022
// Design Name:   BranchControl
// Module Name:   /mnt/Data/IITKGP/Semester 5/COA_Lab/Lab6/RISC/test_Branch.v
// Project Name:  RISC
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: BranchControl
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module test_Branch;

	// Inputs
	reg [5:0] opcode;
	reg zero;
	reg sign;
	reg carry;

	// Outputs
	wire [1:0] PCSrc;

	// Instantiate the Unit Under Test (UUT)
	BranchControl uut (
		.opcode(opcode), 
		.zero(zero), 
		.sign(sign), 
		.carry(carry), 
		.PCSrc(PCSrc)
	);

	initial begin
		$monitor ("op = %b, zero = %b, sign = %b, carry = %b, PCSRC = %b", opcode, zero, sign, carry, PCSrc);
		// Initialize Inputs
		opcode = 0;
		zero = 0;
		sign = 0;
		carry = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		opcode = 6'b100000;
		#10;
		opcode = 6'b100101;
		#10;
		opcode = 6'b010000;
		#10;
		opcode = 6'b100001;
		#10;
		opcode = 6'b100010;
		sign = 1'b1;
		#10;
		opcode = 6'b100011;
		zero = 1'b1;
		#10;
		opcode = 6'b100100;
		zero = 1'b0;
		#10;
		opcode = 6'b100110;
		carry = 1'b1;
		#10;
		opcode = 6'b100111;
		carry = 1'b0;

	end
      
endmodule

