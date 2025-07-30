`include "my_comparator.v"
`timescale 1ns/1ns

module tb_my_comparator;

reg a,b;
wire c1,c2,c3;

my_comparator dut(
    .A(a),
    .B(b),
    .C1(c1),
    .C2(c2),
    .C3(c3)
);

initial begin
    $dumpfile("my_comparator_vcd_file.vcd");
    $dumpvars(0, tb_my_comparator);

    a = 0;b = 0;
    #10;    //there are the timing for wait

    a = 0;b = 1;
    #10;    //there are the timing for wait

    a = 1;b = 0;
    #10;    //there are the timing for wait

    a=1;b=1;
    #10;    //there are the timing for wait


    $display("Test completed !!!!!!!!!!!!!!!!!!");
    $finish;

end

endmodule