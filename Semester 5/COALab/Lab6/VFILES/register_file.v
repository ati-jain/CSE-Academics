`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:48:17 10/26/2022 
// Design Name: 
// Module Name:    register_file 
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
module register_file(
	input clk,
	input rst,
   input RegWrite,
	input [4:0] reg1_addr,
	input [4:0] reg2_addr,
	input [4:0] reg_write_addr,
	input [31:0] write_data,
	output [31:0] data1,
	output [31:0] data2
    );

		 reg [31:0] register[31:0];

		 assign data1 = register[reg1_addr];
		 assign data2 = register[reg2_addr];

    always @(posedge clk or posedge rst)
    begin
		if (rst)
        begin
            register[0] = 0;
            register[1] = 0;
            register[2] = 0;
            register[3] = 0;
            register[4] = 0;
            register[5] = 0;
            register[6] = 0;
            register[7] = 0;
            register[8] = 0;
            register[9] = 0;
            register[10] = 0;
            register[11] = 0;
            register[12] = 0;
            register[13] = 0;
            register[14] = 0;
            register[15] = 0;
            register[16] = 0;
            register[17] = 0;
            register[18] = 0;
            register[19] = 0;
            register[20] = 0;
            register[21] = 0;
            register[22] = 0;
            register[23] = 0;
            register[24] = 0;
            register[25] = 0;
            register[26] = 0;
            register[27] = 0;
            register[28] = 0;
            register[29] = 0;
            register[30] = 0;
            register[31] = 0;
		end
        else if(RegWrite)
        begin
            register[reg_write_addr] = write_data;
        end
    end
	 always @(posedge clk)
	 begin
		$display("reg1 = %d, reg2 = %d, reg3 = %d, reg4 = %d, reg5 = %d, reg31 = %d", $signed(register[1]), register[2], register[3], register[4], register[5], register[31]);
	 end
endmodule
