`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:18:32 10/26/2022 
// Design Name: 
// Module Name:    BranchControl 
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
module BranchControl(
    input [5:0] opcode,
	 input zero,
	 input sign,
	 input carry,
	 output reg [1:0] PCSrc
    );

      always@(*) 
		begin
				if(opcode == 6'b100001) // br
				begin
						PCSrc = 2'b01;
				end
				else if(opcode == 6'b100000) // b
				begin
						PCSrc = 2'b10;
				end
				else if(opcode == 6'b100101) // bl
				begin
						PCSrc = 2'b10;
				end
		      else if(opcode == 6'b100010) // bltz
		      begin		
                  if(sign == 1) // add
				            PCSrc = 2'b10;
				      else  PCSrc = 2'b00;
		      end
		
		      else if(opcode == 6'b100011) // bz
		            begin
		                  if(zero == 1)
				            PCSrc = 2'b10;
				            else  PCSrc = 2'b00;
		            end
		
		      else if(opcode == 6'b100100) // bnz
		      begin
		            if(zero == 0)
				            PCSrc = 2'b10;
			         else PCSrc = 2'b00;
		      end
		
		      else if(opcode == 6'b100110) // bcy
		      begin 
		            if(carry == 1)
				            PCSrc = 2'b10;
			         else PCSrc = 2'b00;
		      end
		
		
		      else if(opcode == 6'b100111) // bncy
		      begin
		            if(carry == 0)
				            PCSrc = 2'b10;
				      else PCSrc = 2'b00;
		      end
		
		      else PCSrc = 2'b00;
		
		end

endmodule
