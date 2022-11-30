`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:28:45 08/31/2022 
// Design Name: 
// Module Name:    wrapperCLA4bitAugmented 
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
module wrapperCLA4bitAugmented(
    input clk, 
	 input rst, 
	 input [3:0] A, 
	 input [3:0] B, 
	 input cin, 
	 output reg [3:0] sum, 
	 output reg Pout,
	 output reg Gout
    );

		reg [3:0] Areg;
		reg [3:0] Breg;
		reg cin_reg;
		wire [3:0] sum_net;
		wire Pout_net;
		wire Gout_net;
		always @(posedge clk)
			 begin
				  if(rst)
						begin
							 Areg<=4'd0;
							 Breg<=4'd0;
							 cin_reg<=1'd0;
							 sum<=4'd0;
							 Pout<=1'd0;
							 Gout<=1'd0;
						end
				  else
						begin
							 Areg<=A;
							 Breg<=B;
							 cin_reg<=cin;
							 sum<=sum_net;
							 Pout<=Pout_net;
							 Gout<=Gout_net;
						end
			 end

		CLA4bitAugmented c(Areg,Breg,cin_reg,sum_net,Pout_net, Gout_net);

endmodule
