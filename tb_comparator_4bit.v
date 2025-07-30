`include "comparator_4bit.v"
`timescale 1ns/1ns

module tb_comparator_4bit;

reg [3:0] a,b;
wire c;

comparator_4bit dut(
    .A(a),
    .B(b),
    .C(c)
);


initial begin

    $dumpfile("comparator_4bit_vcd.vcd");
    $dumpvars(0,tb_comparator_4bit);


    a = 4'b0000 ; b = 4'b0001 ; //it should give c = 0 
    #5;

    a = 4'b0011 ; b = 4'b0011 ; //it should give c = 1
    #5;

    a = 4'd008 ; b = 4'd010 ; //it should give c = 0
    #5;

    a = 3'd004 ; b = 3'd004 ; //it should give c = 0
    #5;


    $display("Test completed !!!!!!!!");
    $finish;
end

endmodule