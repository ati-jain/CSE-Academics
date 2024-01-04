`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   16:16:52 10/26/2022
// Design Name:   RISC
// Module Name:   /mnt/Data/IITKGP/Semester 5/COA_Lab/Lab6/RISC/test_RISC.v
// Project Name:  RISC
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: RISC
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module test_RISC;

	// Inputs
	reg clk;
	reg rst;
	reg Return;

	// Instantiate the Unit Under Test (UUT)
	RISC uut (
		.clk(clk), 
		.rst(rst),
		.Return(
	);
	
	always #2 clk = ~clk;

	initial begin
		// Initialize Inputs
		$monitor("%d", Return);
		clk = 0;
		rst = 1;
		#10;
		
		
		rst = 0;
		
        
		// Add stimulus here

	end
      
endmodule

