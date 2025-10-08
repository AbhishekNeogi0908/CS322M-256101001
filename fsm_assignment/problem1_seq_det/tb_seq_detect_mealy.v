`timescale 1ns/1ns
`include "seq_detect_mealy.v"

module tb_seq_detector;

    reg clk, rst, din;
    wire y;

    // DUT instance
    seq_detector dut (
        .clk(clk),
        .rst(rst),
        .din(din),
        .y(y)
    );

    // Clock generation: period = 10
    initial clk = 0;
    always #5 clk = ~clk;

    // Stimulus
    initial begin 
        $dumpfile("seq_detector_vcd_file.vcd");
        $dumpvars(0, tb_seq_detector);

        // Apply reset
        rst = 1; 
        din = 0;
        #10;         // keep reset active for 1 clock cycle
        rst = 0; 

        // Drive inputs: 1101 should trigger detection
        din = 1; #10;
        din = 1; #10;
        din = 0; #10;
        din = 1; #10;  // <-- sequence 1101 detected here

        // Extra inputs
        din = 0; #10;
        din = 1; #10;
        din = 1; #10;
        din = 0; #10;
        din = 1; #10;

        $display("Test completed!");
        $finish;
    end

    // Monitor signals
    initial begin
        $display("Time\tclk\trst\tdin\ty");
        $monitor("%0t\t%b\t%b\t%b\t%b", $time, clk, rst, din, y);
    end

endmodule
