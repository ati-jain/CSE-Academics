`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   15:41:14 10/28/2022
// Design Name:   Controller
// Module Name:   /mnt/Data/IITKGP/Semester 5/COA_Lab/Lab6/RISC/test_Controller.v
// Project Name:  RISC
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Controller
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module test_Controller;

	// Inputs
	reg [5:0] opcode;
	reg [5:0] func_code;

	// Outputs
	wire [1:0] mem_to_reg;
	wire [3:0] aluOp;
	wire [1:0] aluSrc;
	wire regDst;
	wire regWrite;
	wire memRead;
	wire memWrite;

	// Instantiate the Unit Under Test (UUT)
	Controller uut (
		.opcode(opcode), 
		.func_code(func_code), 
		.mem_to_reg(mem_to_reg), 
		.aluOp(aluOp), 
		.aluSrc(aluSrc), 
		.regDst(regDst), 
		.regWrite(regWrite), 
		.memRead(memRead), 
		.memWrite(memWrite)
	);

	initial begin
		$monitor ("op = %b, func = %b, memtoreg = %b, aluop = %b, alusrc = %b, regdst = %b, regwrite = %b, memread = %b, memwrite = %b", opcode, func_code, mem_to_reg, aluOp, aluSrc, regDst, regWrite, memRead, memWrite);
		// Initialize Inputs
		opcode = 0;
		func_code = 0;

		// Wait 100 ns for global reset to finish
		#100;
		opcode = 6'b000000;
		func_code = 6'b000001;
		#10
		opcode = 6'b000001;
		func_code = 6'b000000;
		#10
		opcode = 6'b000010;
		func_code = 6'b000101;
		#10
		opcode = 6'b010001;
		func_code = 0;
		#10
		opcode = 6'b000010;
		func_code = 6'b000110;
		#10
		opcode = 6'b010011;
		func_code = 0;
		#10
		opcode = 6'b100000;
		#10
		opcode = 6'b100001;
		#10
		opcode = 6'b100010;
		#10
		opcode = 6'b100011;
		#10
		opcode = 6'b100100;
		#10
		opcode = 6'b100101;
		#10
		opcode = 6'b100110;
		#10
		opcode = 6'b100111;
        
		// Add stimulus here

	end
      
endmodule

