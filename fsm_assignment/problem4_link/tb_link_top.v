`timescale 1ns/1ps
`include "link_top.v"
module tb_link_top;

    reg clk, rst;
    wire done;

    link_top dut(.clk(clk), .rst(rst), .done(done));

    // Clock
    always #5 clk = ~clk;

    initial begin
        $dumpfile("master_slave.vcd");
        $dumpvars(0, tb_link_top);

        clk = 0;
        rst = 1;
        #15 rst = 0;   // release reset

        wait(done);
        #20;
        $finish;
    end

endmodule
