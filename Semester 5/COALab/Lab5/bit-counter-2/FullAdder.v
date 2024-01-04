`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:47:18 09/14/2022 
// Design Name: 
// Module Name:    FullAdder 
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
module FullAdder(input X, Y, cin, output sum, cout);
  wire w1,w2,w3;
  //Structural code for one bit full adder
  xor G1(w1, X, Y);
  xor G2(sum, w1, cin);
  and G3(w2, w1, cin);
  and G4(w3, X, Y);
  or G5(cout, w2, w3);
endmodule
