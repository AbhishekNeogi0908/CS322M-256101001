`timescale 1ns/1ns
`include "myxor.v"
module tb;

reg a,b;
wire c;

myxor dut(
        .A(a), 
        .B(b),
        .C(c)

);

initial begin
    $dumpfile("myxor.vcd");
    $dumpvars(0, tb);


    a = 0;b = 0;
    #10;    //there are the timing for wait

    a = 0;b = 1;
    #10;    //there are the timing for wait

    a = 1;b = 0;
    #10;    //there are the timing for wait

    a=1;b=1;
    #10;    //there are the timing for wait


    $display("Test completed");
    $finish;
    
end

endmodule