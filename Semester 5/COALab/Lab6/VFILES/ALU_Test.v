`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   16:48:00 10/21/2022
// Design Name:   ALU
// Module Name:   /mnt/Data/IITKGP/Semester 5/COA_Lab/Lab3/part-1/RISC/ALU_Test.v
// Project Name:  RISC
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: ALU
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module ALU_Test;

	// Inputs
	reg [31:0] A;
	reg [31:0] B;
	reg [3:0] ALUOp;

	// Outputs
	wire [31:0] out;
	wire zero;
	wire sign;
	wire carry;

	// Instantiate the Unit Under Test (UUT)
	ALU uut (
		.A(A), 
		.B(B), 
		.ALUOp(ALUOp), 
		.out(out), 
		.zero(zero), 
		.sign(sign), 
		.carry(carry)
	);

	initial begin
		$monitor("A = %d, B = %d, ALUOp = %d, out = %d, zero = %d, sign = %d, carry = %d", A, B, ALUOp, out, zero, sign, carry);
		// Initialize Inputs
		A = 32'b0111;
		B = 32'b0011;
		ALUOp = 4'b0001;

		// Wait 100 ns for global reset to finish
		#100;
		A = 32'b0111;
		B = 32'b0011;
		ALUOp = 4'b0010;
		
		#100;
		A = 32'b0111;
		B = 32'b0011;
		ALUOp = 4'b0011;
		
		#100;
		A = 32'b0111;
		B = 32'b0011;
		ALUOp = 4'b0100;

		#100;
		A = 32'b0111;
		B = 32'b0011;
		ALUOp = 4'b0101;

		#100;
		A = 32'b0111;
		B = 32'b0011;
		ALUOp = 4'b0110;
		
		#100;
		A = 32'b0111;
		B = 32'b0011;
		ALUOp = 4'b0111;
		
		#100;
		A = 32'b10001111111111100000000001111111;
		B = 32'b0011;
		ALUOp = 4'b0111;
		
		#100;
		A = 32'b0111;
		B = 32'b0011;
		ALUOp = 4'b1000;
		// Add stimulus here

	end
      
endmodule

