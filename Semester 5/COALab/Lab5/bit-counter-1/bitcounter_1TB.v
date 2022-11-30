`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   02:14:53 09/14/2022
// Design Name:   bitcounter_1
// Module Name:   /home/suneetha/Documents/bitcounter1/bitcounter_1TB.v
// Project Name:  bitcounter1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: bitcounter_1
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module bitcounter_1TB;

	// Inputs
	reg clk;
	reg reset;

	// Outputs
	wire [3:0] counter;

	// Instantiate the Unit Under Test (UUT)
	bitcounter_1 uut (
		.clk(clk), 
		.reset(reset), 
		.counter(counter)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		reset = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		forever #250 clk=~clk;
		
    end
	 
    initial begin
      reset=1;
      #20;
      reset=0;
		#252;
		reset=1;
		#20;
		reset=0;

	end
      
endmodule
