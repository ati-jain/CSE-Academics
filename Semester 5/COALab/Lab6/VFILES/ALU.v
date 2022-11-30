`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:54:49 10/21/2022 
// Design Name: 
// Module Name:    ALU 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module ALU(
	input [31:0] A,
	input [31:0] B,
	input [3:0] ALUOp,
	output reg [31:0] out,
	output reg zero,
	output reg sign,
	output reg carry
    );

	wire [31:0] ADD, AND, XOR, COMP, SHLL, SHRL, SHRA, DIFF;
	wire z, c;

	zero_32bit op1(A, z);
	adder_32bit op2(A, B, ADD, c);
	and_32bit op3(A, B, AND);
	xor_32bit op4(A, B, XOR);
	comp_32bit op5(A, COMP);
	shll_32bit op6(A, B, SHLL);
	shrl_32bit op7(A, B, SHRL);
	shra_32bit op8(A, B, SHRA);
	diff_32bit op9(A, B, DIFF);

	always@(*)
	begin
	carry = c;
	zero = z;
		case(ALUOp)
			4'b0001:
			begin
				sign = ADD[31];
				out = ADD;
			end
			4'b0010:
			begin
				sign = COMP[31];
				out = COMP;
			end
			4'b0011:
			begin
				sign = AND[31];
				out = AND;
			end
			4'b0100:
			begin
				sign = XOR[31];
				out = XOR;
			end
			4'b0101:
			begin
				sign = SHLL[31];
				out = SHLL;
			end
			4'b0110:
			begin
				sign = SHRL[31];
				out = SHRL;
			end
			4'b0111:
			begin
				sign = SHRA[31];
				out = SHRA;
			end
			4'b1000:
			begin
				sign = DIFF[31];
				out = DIFF;
			end
			default:
			begin
				sign = 1'b0;
				out = 32'b0;
			end
		endcase
	end

endmodule
