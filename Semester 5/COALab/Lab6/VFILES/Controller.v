`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:15:48 10/26/2022 
// Design Name: 
// Module Name:    Controller 
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
module Controller(
    input [5:0] opcode,
    input [5:0] func_code,
    //input reset,
    output reg [1:0]mem_to_reg,
    output reg [3:0]aluOp,
    output reg [1:0]aluSrc,
    output reg regDst,
    output reg regWrite,
    output reg memRead,
    output reg memWrite
    //output reg [1:0]PCSrc
    );

      always@(*) begin
		if(opcode == 6'b000000) 
		begin		
            if(func_code == 6'b000000) // add
				begin 
				      mem_to_reg = 2'b10;
                  aluOp = 4'b0001;
                  aluSrc = 2'b00;
                  regDst = 0;
                  regWrite = 1;
                  memRead = 0;
                  memWrite = 0;
                  //PCSrc = 2'b00;
		      end
		      
				else if(func_code == 6'b000001) // comp
				begin
				      mem_to_reg = 2'b10;
                  aluOp = 4'b0010;
                  aluSrc = 2'b00;
                  regDst = 0;
                  regWrite = 1;
                  memRead = 0;
                  memWrite = 0;
                  //PCSrc = 2'b00;
				end
		end
		
		else if(opcode == 6'b000001)
		begin
		      if(func_code == 6'b000000) // and
				begin
				      mem_to_reg = 2'b10;
                  aluOp = 4'b0011;
                  aluSrc = 2'b00;
                  regDst = 0;
                  regWrite = 1;
                  memRead = 0;
                  memWrite = 0;
                  //PCSrc = 2'b00;
				end
				
				else if(func_code == 6'b000001) // xor
				begin
				      mem_to_reg = 2'b10;
                  aluOp = 4'b0100;
                  aluSrc = 2'b00;
                  regDst = 0;
                  regWrite = 1;
                  memRead = 0;
                  memWrite = 0;
                  //PCSrc = 2'b00;
				end
		end
			
		else if(opcode == 6'b000010)
		begin
		      if(func_code == 6'b000000) // shll
				begin
				      mem_to_reg = 2'b10;
                  aluOp = 4'b0101;
                  aluSrc = 2'b01;
                  regDst = 0;
                  regWrite = 1;
                  memRead = 0;
                  memWrite = 0;
                  //PCSrc = 2'b00;
				end
				else if(func_code == 6'b000001) // shrl
				begin
				      mem_to_reg = 2'b10;
                  aluOp = 4'b0110;
                  aluSrc = 2'b01;
                  regDst = 0;
                  regWrite = 1;
                  memRead = 0;
                  memWrite = 0;
                  //PCSrc = 2'b00;
		      end
				else if(func_code == 6'b000010) // shllv
				begin
				      mem_to_reg = 2'b10;
                  aluOp = 4'b0101;
                  aluSrc = 2'b00;
                  regDst = 0;
                  regWrite = 1;
                  memRead = 0;
                  memWrite = 0;
                  //PCSrc = 2'b00;
		      end
				else if(func_code == 6'b000011) // shrlv
				begin
				      mem_to_reg = 2'b10;
                  aluOp = 4'b0110;
                  aluSrc = 2'b00;
                  regDst = 0;
                  regWrite = 1;
                  memRead = 0;
                  memWrite = 0;
                  //PCSrc = 2'b00;
		      end
				else if(func_code == 6'b000100) // shra
				begin
				      mem_to_reg = 2'b10;
                  aluOp = 4'b0111;
                  aluSrc = 2'b01;
                  regDst = 0;
                  regWrite = 1;
                  memRead = 0;
                  memWrite = 0;
                  //PCSrc = 2'b00;
		      end
				else if(func_code == 6'b000101) // shrav
				begin
				      mem_to_reg = 2'b10;
                  aluOp = 4'b0111;
                  aluSrc = 2'b00;
                  regDst = 0;
                  regWrite = 1;
                  memRead = 0;
                  memWrite = 0;
                  //PCSrc = 2'b00;
		      end
				else if(func_code == 6'b000110) // diff
				begin
				      mem_to_reg = 2'b10;
                  aluOp = 4'b1000;
                  aluSrc = 2'b00;
                  regDst = 0;
                  regWrite = 1;
                  memRead = 0;
                  memWrite = 0;
                  //PCSrc = 2'b00;
		      end
		end
		
		else if(opcode == 6'b010000) // addi
		begin
		      mem_to_reg = 2'b10;
            aluOp = 4'b0001;
            aluSrc = 2'b10;
            regDst = 0;
            regWrite = 1;
            memRead = 0;
            memWrite = 0;
            //PCSrc = 2'b00;
		end
		
		else if(opcode == 6'b010001) // compi
		begin
		      mem_to_reg = 2'b10;
            aluOp = 4'b0010;
            aluSrc = 2'b10;
            regDst = 0;
            regWrite = 1;
            memRead = 0;
            memWrite = 0;
            //PCSrc = 2'b00;
		end
		
		else if(opcode == 6'b010010) // lw
		begin
		      mem_to_reg = 2'b01;
            aluOp = 4'b0001;
            aluSrc = 2'b10;
            regDst = 0;
            regWrite = 1;
            memRead = 1;
            memWrite = 0;
            //PCSrc = 2'b00;
		end
		
		else if(opcode == 6'b010011) // sw
		begin
		      //mem_to_reg = 2'b01;
            aluOp = 4'b0001;
            aluSrc = 2'b10;
            regDst = 0;
            regWrite = 0;
            memRead = 0;
            memWrite = 1;
            //PCSrc = 2'b00;
		end
		
		else if(opcode == 6'b100000) // b
		begin
		      //mem_to_reg = 2'b01;
            //aluOp = 4'b0001;
            aluSrc = 2'b10;
            //regDst = 0;
            regWrite = 0;
            memRead = 0;
            memWrite = 0;
            //PCSrc = 2'b10;
		end
		
		else if(opcode == 6'b100001) // br
		begin
		      //mem_to_reg = 2'b01;
            //aluOp = 4'b0001;
            aluSrc = 2'b01;
            //regDst = 0;
            regWrite = 0;
            memRead = 0;
            memWrite = 0;
            //PCSrc = 2'b01;
		end
		
		else if(opcode == 6'b100010) // bltz
		begin
		      //mem_to_reg = 2'b01;
            aluOp = 4'b0000;
            //aluSrc = 2'b10;
            //regDst = 0;
            regWrite = 0;
            memRead = 0;
            memWrite = 0;
            //PCSrc = 2'b10;
		end
		
		else if(opcode == 6'b100011) // bz
		begin
		      //mem_to_reg = 2'b01;
            aluOp = 4'b0000;
            //aluSrc = 2'b10;
            //regDst = 0;
            regWrite = 0;
            memRead = 0;
            memWrite = 0;
            //PCSrc = 2'b10;
		end
		
		else if(opcode == 6'b100100) // bnz
		begin
		      //mem_to_reg = 2'b01;
            aluOp = 4'b0000;
            //aluSrc = 2'b10;
            //regDst = 0;
            regWrite = 0;
            memRead = 0;
            memWrite = 0;
            //PCSrc = 2'b10;
		end
		
		else if(opcode == 6'b100101) // bl
		begin
		      mem_to_reg = 2'b00;
            //aluOp = 4'b0000;
            //aluSrc = 2'b10;
            regDst = 1;
            regWrite = 1;
            memRead = 0;
            memWrite = 0;
            //PCSrc = 2'b10;
		end
		
		else if(opcode == 6'b100110) // bcy
		begin
		      //mem_to_reg = 2'b01;
            aluOp = 4'b0000;
            //aluSrc = 2'b10;
            //regDst = 0;
            regWrite = 0;
            memRead = 0;
            memWrite = 0;
            //PCSrc = 2'b10;
		end
		
		else if(opcode == 6'b100111) // bncy
		begin
		      //mem_to_reg = 2'b01;
            aluOp = 4'b0000;
            //aluSrc = 2'b10;
            //regDst = 0;
            regWrite = 0;
            memRead = 0;
            memWrite = 0;
            //PCSrc = 2'b10;
		end
		
	end
	
endmodule
