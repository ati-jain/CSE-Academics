`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   16:30:08 10/28/2022
// Design Name:   mux_2x1
// Module Name:   /mnt/Data/IITKGP/Semester 5/COA_Lab/Lab6/RISC/test_mux_2x1.v
// Project Name:  RISC
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: mux_2x1
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module test_mux_2x1;

	// Inputs
	reg [4:0] in1;
	reg [4:0] in2;
	reg signal;

	// Outputs
	wire [4:0] out;

	// Instantiate the Unit Under Test (UUT)
	mux_2x1 uut (
		.in1(in1), 
		.in2(in2), 
		.signal(signal), 
		.out(out)
	);

	initial begin
		$monitor("in1 = %b, in2 = %b, signal = %b, out = %b", in1, in2, signal, out);
		// Initialize Inputs
		in1 = 5'b0;
		in2 = 5'b1;
		signal = 0;

		// Wait 100 ns for global reset to finish
		#100;
		in1 = 5'b0;
		in2 = 5'b1;
		signal = 1;
        
		// Add stimulus here

	end
      
endmodule

