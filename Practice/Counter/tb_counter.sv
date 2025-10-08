`timescale 1ns/1ps

module tb_counter;
 localparam WIDTH=4;
 logic clk=0,rst_n=0,en=0,up=1;
 logic [WIDTH-1:0] q;

 counter #(.WIDTH(WIDTH)) dut(.clk,.rst_n,.en,.up,.q);

 //100MHz-ish clk
 always #5 clk=~clk; //10ns clock preiod

 task step(input int n=1); repeat(n) @(posedge clk); endtask

 initial begin
    $dumpfile("counter.vcd"); $dumpvars(0,tb_counter);

    //release reset
    step(1);rst_n=1;step(1);rst_n=0;

    // count upto 3 steps
    en=1;up=1;step(3);
    assert(q==3) else $fatal(1,"count up failed,q=%0d",q);

    // count down to 2 steps
    up=0;step(2);
    assert(q==1) else $fatal(1,"down count failed,q=%0d",q);

    //hold
    en=0;step(3);
    assert(q==1) else $fatal(1,"hold failed");


    $display("Counter test finished");
    $finish;
 end
endmodule