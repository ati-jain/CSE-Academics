`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   15:55:20 10/28/2022
// Design Name:   register_file
// Module Name:   /mnt/Data/IITKGP/Semester 5/COA_Lab/Lab6/RISC/test_regfile.v
// Project Name:  RISC
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: register_file
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module test_regfile;

	// Inputs
	reg clk;
	reg rst;
	reg RegWrite;
	reg [4:0] reg1_addr;
	reg [4:0] reg2_addr;
	reg [4:0] reg_write_addr;
	reg [31:0] write_data;

	// Outputs
	wire [31:0] data1;
	wire [31:0] data2;

	// Instantiate the Unit Under Test (UUT)
	register_file uut (
		.clk(clk), 
		.rst(rst), 
		.RegWrite(RegWrite), 
		.reg1_addr(reg1_addr), 
		.reg2_addr(reg2_addr), 
		.reg_write_addr(reg_write_addr), 
		.write_data(write_data), 
		.data1(data1), 
		.data2(data2)
	);

	initial begin
		$monitor("reg1_addr = %d, reg2_addr = %d, reg_write_addr = %d, wirte_data = %d, data1 = %d, data2 = %d", reg1_addr, reg2_addr, reg_write_addr, write_data, data1, data2);
		// Initialize Inputs
		clk = 0;
		rst = 1;
		RegWrite = 0;
		reg1_addr = 0;
		reg2_addr = 0;
		reg_write_addr = 0;
		write_data = 0;

		// Wait 100 ns for global reset to finish
		#100;
		reg1_addr = 5'b00010;
		reg2_addr = 5'b00001;
		write_data = 32'b0;
		RegWrite = 1'b0;
		
		#100
		reg1_addr = 5'b00011;
		reg2_addr = 5'b00001;
		reg_write_addr = 5'b00001;
		write_data = 32'b00000000000000000010000100010000;
		RegWrite = 1'b1;
		rst = 1;
		
		// Add stimulus here

	end
      
endmodule

