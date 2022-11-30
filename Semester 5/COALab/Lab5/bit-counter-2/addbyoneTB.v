`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   02:02:54 09/14/2022
// Design Name:   addbyone
// Module Name:   /home/suneetha/Documents/bitcounter2/addbyoneTB.v
// Project Name:  bitcounter2
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: addbyone
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module addbyoneTB;

	// Inputs
	reg [3:0] A;

	// Outputs
	wire [3:0] sum;

	// Instantiate the Unit Under Test (UUT)
	addbyone uut (
		.A(A), 
		.sum(sum)
	);

	initial begin
		// Initialize Inputs
		A = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		A = 4'd2;
		#100;
		A = 4'd7;
		#100;
		A = 4'd8;
		#100;
		A = 4'd10;
		#100;
		A = 4'd12;
		#100;
		A = 4'd15;

	end
      
endmodule

