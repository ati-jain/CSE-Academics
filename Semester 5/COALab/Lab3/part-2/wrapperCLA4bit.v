`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    09:33:18 08/31/2022 
// Design Name: 
// Module Name:    wrapperCLA4bit 
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
module wrapperCLA4bit(
    input clk, 
	 input rst, 
	 input [3:0] A, 
	 input [3:0] B, 
	 input cin, 
	 output reg [3:0] sum, 
	 output reg cout
    );

		reg [3:0] Areg;
		reg [3:0] Breg;
		reg cin_reg;
		wire [3:0] sum_net;
		wire cout_net;
		always @(posedge clk)
			 begin
				  if(rst)
						begin
							 Areg<=4'd0;
							 Breg<=4'd0;
							 cin_reg<=1'd0;
							 sum<=4'd0;
							 cout<=1'd0;
						end
				  else
						begin
							 Areg<=A;
							 Breg<=B;
							 cin_reg<=cin;
							 sum<=sum_net;
							 cout<=cout_net;
						end
			 end

		CLA4bit c(Areg,Breg,cin_reg,sum_net,cout_net);

endmodule
