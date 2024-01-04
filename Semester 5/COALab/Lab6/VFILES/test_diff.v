`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   16:42:06 10/21/2022
// Design Name:   diff_32bit
// Module Name:   /mnt/Data/IITKGP/Semester 5/COA_Lab/Lab3/part-1/RISC/test_diff.v
// Project Name:  RISC
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: diff_32bit
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module test_diff;

	// Inputs
	reg [31:0] A;
	reg [31:0] B;

	// Outputs
	wire [4:0] LSB;

	// Instantiate the Unit Under Test (UUT)
	diff_32bit uut (
		.A(A), 
		.B(B), 
		.LSB(LSB)
	);

	initial begin
		// Initialize Inputs
		A = 32'b00100;
		B = 32'b1000;
		// Wait 100 ns for global reset to finish
		#100;
		A = 32'b110000;
		B = 32'b111111;
        
		// Add stimulus here

	end
      
endmodule

