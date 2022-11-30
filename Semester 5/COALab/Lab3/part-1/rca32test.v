`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   12:55:55 08/26/2022
// Design Name:   Ripple32bit
// Module Name:   /mnt/Data/IITKGP/Semester_5/COA_Lab/Lab3/Verilog Demo/ISE Project/RippleCarryAdder/rca32test.v
// Project Name:  RippleCarryAdder
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Ripple32bit
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module rca32test;

	// Inputs
	reg [31:0] a;
	reg [31:0] b;
	reg cin;

	// Outputs
	wire [31:0] s;
	wire cout;

	// Instantiate the Unit Under Test (UUT)
	Ripple32bit uut (
		.a(a), 
		.b(b), 
		.cin(cin), 
		.s(s), 
		.cout(cout)
	);

	initial begin
		$monitor ("a = %d, b = %d, cin = %d, s = %d, cout = %d", a, b, cin, s, cout);
		// Initialize Inputs
		// general cases
		a = 32'd171798691; b = 32'd1717986; cin = 0;
		#100;
		a = 32'd12345678; b = 32'd98765432; cin = 1;
		#100;
		a = 32'd4294967290; b = 32'd5; cin = 0;
		#100;
		
		//corner cases
		a = 32'd1073741824; b = 32'd1073741824; cin = 0;
		#100;
		a = 32'd2147483640; b = 32'd4; cin = 0;
		#100;
		a = 32'd2147483648; b = 0; cin = 0;
	end
      
endmodule

