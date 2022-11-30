`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   16:26:08 10/28/2022
// Design Name:   mux_3x1
// Module Name:   /mnt/Data/IITKGP/Semester 5/COA_Lab/Lab6/RISC/test_mux_3x1.v
// Project Name:  RISC
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: mux_3x1
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module test_mux_3x1;

	// Inputs
	reg [31:0] in1;
	reg [31:0] in2;
	reg [31:0] in3;
	reg [1:0] signal;

	// Outputs
	wire [31:0] out;

	// Instantiate the Unit Under Test (UUT)
	mux_3x1 uut (
		.in1(in1), 
		.in2(in2), 
		.in3(in3), 
		.signal(signal), 
		.out(out)
	);

	initial begin
		$monitor("in1 = %b, in2 = %b, in3 = %b, signal = %b, out = %b", in1, in2, in3, signal, out);
		// Initialize Inputs
		in1 = 32'b1;
		in2 = 32'b0;
		in3 = 32'b11;
		signal = 2'b00;

		// Wait 100 ns for global reset to finish
		#100;
		in1 = 32'b1;
		in2 = 32'b0;
		in3 = 32'b11;
		signal = 2'b01;
		
		#100;
		in1 = 32'b1;
		in2 = 32'b0;
		in3 = 32'b11;
		signal = 2'b10;
        
		// Add stimulus here

	end
      
endmodule

