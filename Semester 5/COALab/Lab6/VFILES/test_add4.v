`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   12:33:03 10/26/2022
// Design Name:   add4
// Module Name:   /mnt/Data/IITKGP/Semester 5/COA_Lab/Lab6/RISC/test_add4.v
// Project Name:  RISC
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: add4
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module test_add4;

	// Inputs
	reg [31:0] in;

	// Instantiate the Unit Under Test (UUT)
	add4 uut (
		.in(in)
	);

	initial begin
		// Initialize Inputs
		in = 0;

		// Wait 100 ns for global reset to finish
		#100;
		
		in = 32'b100;
        
		// Add stimulus here

	end
      
endmodule

