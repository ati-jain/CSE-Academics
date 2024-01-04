`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   12:13:44 08/26/2022
// Design Name:   RippleCarryAdder
// Module Name:   /mnt/Data/IITKGP/Semester_5/COA_Lab/Lab3/Verilog Demo/ISE Project/RippleCarryAdder/testrca.v
// Project Name:  RippleCarryAdder
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: RippleCarryAdder
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module testrca;

	// Inputs
	reg [7:0] a;
	reg [7:0] b;
	reg cin;

	// Outputs
	wire [7:0] s;
	wire cout;

	// Instantiate the Unit Under Test (UUT)
	RippleCarryAdder uut (
		.a(a), 
		.b(b), 
		.cin(cin), 
		.s(s), 
		.cout(cout)
	);

	initial begin
	$monitor ("a = %d, b = %d, cin = %d, s = %d, cout = %d", a, b, cin, s, cout);
		// Initialize Inputs
		//general cases
		a = 8'd53; b = 8'd52; cin = 0;
		#100;
		a = 8'd53; b = 8'd52; cin = 1;
		#100;
		//corner cases
		a = 8'd128; b = 8'd0; cin = 0;
		#100;
		a = 8'd64; b = 8'd64; cin = 1;
		#100;
		a = 8'd100; b = 8'd28; cin = 0;
	end
      
endmodule

