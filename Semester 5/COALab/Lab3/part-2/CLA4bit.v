`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    22:48:09 08/30/2022 
// Design Name: 
// Module Name:    CLA4bit 
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
module CLA4bit(
    input [3:0] A,
    input [3:0] B,
    input cin,
    output [3:0] sum,
    output cout
    );
	
	wire [3:0] G, P, C; // wires for carry generate, carry propagate and actual carries
	
	// calculating bitwise generate and propagate
	assign G = A & B; // G[i] = A[i] AND B[i]
	assign P = A ^ B; // P[i] = A[i] XOR B[i]
	
	// calculate subsequent carries using generates and propagates
	// C[i + 1] = G[i] OR (P[i] AND C[i])
	assign C[0] = cin;
	assign C[1] = G[0] | (P[0] & C[0]);
	assign C[2] = G[1] | (P[1] & G[0]) | (P[1] & P[0] & C[0]);
	assign C[3] = G[2] | (P[2] & G[1]) | (P[2] & P[1] & G[0]) | (P[2] & P[1] & P[0] & C[0]);
	assign cout = G[3] | (P[3] & G[2]) | (P[3] & P[2] & G[1]) | (P[3] & P[2] & P[1] & G[0]) | (P[3] & P[2] & P[1] & P[0] & C[0]);
	
	// calculate final sum using propagate and carries
	assign sum = P ^ C; // S[i] = P[i] XOR C[i]

endmodule
