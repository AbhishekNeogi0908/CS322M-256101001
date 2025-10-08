`timescale 1ns/1ns
`include "traffic_light.v"

module tb_traffic_light;
    reg clk, rst, tick;
    wire ns_g, ns_y, ns_r, ew_g, ew_y, ew_r;

    traffic_light dut(
        .clk(clk),
        .rst(rst),
        .tick(tick),
        .ns_g(ns_g), .ns_y(ns_y), .ns_r(ns_r),
        .ew_g(ew_g), .ew_y(ew_y), .ew_r(ew_r)
    );

    // Clock gen (10ns period)
    initial clk = 0;
    always #5 clk = ~clk;

    // Tick gen (simulate 1 Hz tick as pulse every 20 time units)
    initial begin
        tick = 0;
        forever begin
            #20 tick = 1;
            #10 tick = 0;
        end
    end

    initial begin
        $dumpfile("traffic_light.vcd");
        $dumpvars(0, tb_traffic_light);

        rst = 1; #10;
        rst = 0;

        // Run for 200 time units (~10 ticks)
        #400;
        $display("Simulation complete!");
        $finish;
    end

    initial begin
        $display("Time\t clk rst tick | NS_g NS_y NS_r | EW_g EW_y EW_r");
        $monitor("%4t\t %b   %b   %b   |   %b    %b    %b  |   %b    %b    %b",
                  $time, clk, rst, tick, ns_g, ns_y, ns_r, ew_g, ew_y, ew_r);
    end
endmodule
