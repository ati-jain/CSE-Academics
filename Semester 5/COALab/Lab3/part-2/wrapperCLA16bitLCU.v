`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:14:03 08/31/2022 
// Design Name: 
// Module Name:    wrapperCLA16bitLCU 
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
module wrapperCLA16bitLCU(
    input clk, 
	 input rst, 
	 input [15:0] A,
    input [15:0] B,
    input cin,
    output reg [15:0] sum,
    output reg cout,
	 output reg Pout,
	 output reg Gout
    );
		reg [15:0] Areg;
		reg [15:0] Breg;
		reg cin_reg;
		wire [15:0] sum_net;
		wire cout_net;
		wire P_out;
		wire G_out;
		always @(posedge clk)
			 begin
				  if(rst)
						begin
							 Areg<=16'd0;
							 Breg<=16'd0;
							 cin_reg<=1'd0;
							 sum<=16'd0;
							 cout<=1'd0;
							 Pout<=1'd0;
							 Gout<=1'd0;
						end
				  else
						begin
							 Areg<=A;
							 Breg<=B;
							 cin_reg<=cin;
							 sum<=sum_net;
							 cout<=cout_net;
							 Pout<=P_out;
							 Gout<=G_out;
						end
			 end

		CLA16bitLCU c(Areg,Breg,cin_reg,sum_net,cout_net, P_out, G_out);

endmodule
