`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:16:00 10/21/2022 
// Design Name: 
// Module Name:    LookaheadCarryUnit 
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
module LookaheadCarryUnit(
    input cin,
    input [3:0] P,
    input [3:0] G,
    output [4:1] C,
    output Pout,
    output Gout
    );
	 
	// calculate the lookahead carries using block propagate and generate from previous level
	assign C[1] = G[0] | (P[0] & cin);
	assign C[2] = G[1] | (P[1] & G[0]) | (P[1] & P[0] & cin);
	assign C[3] = G[2] | (P[2] & G[1]) | (P[2] & P[1] & G[0]) | (P[2] & P[1] & P[0] & cin);
	assign C[4] = G[3] | (P[3] & G[2]) | (P[3] & P[2] & G[1]) | (P[3] & P[2] & P[1] & G[0]) | (P[3] & P[2] & P[1] & P[0] & cin);
	
	assign Pout = P[3] & P[2] & P[1] & P[0];
	assign Gout = G[3] | (P[3] & G[2]) | (P[3] & P[2] & G[1]) | (P[3] & P[2] & P[1] & G[0]);

endmodule
