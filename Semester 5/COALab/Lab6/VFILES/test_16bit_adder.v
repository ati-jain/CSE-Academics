`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   14:41:59 10/21/2022
// Design Name:   CLA_16bit_LCU
// Module Name:   /mnt/Data/IITKGP/Semester 5/COA_Lab/Lab3/part-1/RISC/test_16bit_adder.v
// Project Name:  RISC
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: CLA_16bit_LCU
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module test_16bit_adder;

	// Inputs
	reg [15:0] A;
	reg [15:0] B;
	reg cin;

	// Outputs
	wire [15:0] sum;
	wire cout;

	// Instantiate the Unit Under Test (UUT)
	CLA_16bit_LCU uut (
		.A(A), 
		.B(B), 
		.cin(cin), 
		.sum(sum), 
		.cout(cout)
	);

	initial begin
		// Initialize Inputs
		$monitor ("A = %d, B = %d, cin = %d, sum = %d, cout = %d", A, B, cin, sum, cout);
		// Initialize Inputs
		A = 16'd3245; B = 16'd16785; cin = 0;
		#100;
		A = 16'd3245; B = 16'd16785; cin = 1;
		#100;
		A = 16'd25000; B = 16'd40535; cin = 0;
		#100;
		A = 16'd25001; B = 16'd40535; cin = 0;
		#100;
		A = 16'd25000; B = 16'd40535; cin = 1;
	end
      
endmodule

