`timescale 1ns/1ns
`include "vending_mealy.v"

module tb_vending_mealy;

    reg clk, rst;
    reg [1:0] coin;
    wire [1:0] state;
    wire dispense, chg5;

    // DUT instantiation
    vending_mealy dut(
        .clk(clk),
        .rst(rst),
        .coin(coin),
        .state(state),
        .dispense(dispense),
        .chg5(chg5)
    );

    // Clock generation (10ns period)
    initial clk = 0;
    always #5 clk = ~clk;

    // Test sequence
    initial begin
        $dumpfile("vending_mealy.vcd");
        $dumpvars(0, tb_vending_mealy);

        $display("Time\t clk rst coin state dispense chg5");

        // Apply reset
        rst = 1; coin = 2'b00;
        #12; 
        rst = 0;

        // Insert 5 -> 10 -> 5 (total=20, dispense)
        coin = 2'b01; #10;  // +5
        coin = 2'b10; #10;  // +10
        coin = 2'b01; #10;  // +5 => dispense

        // Insert 10 -> 10 (total=20, dispense)
        coin = 2'b10; #10;
        coin = 2'b10; #10;

        // Insert 10 -> 10 -> 10 (total=30, should dispense + return 5)
        coin = 2'b10; #10;
        coin = 2'b10; #10;
        coin = 2'b10; #10;

        // Idle input
        coin = 2'b00; #20;

        $display("Simulation completed!");
        $finish;
    end

    // Monitor signals
    initial begin
        $monitor("%g\t %b   %b   %b    %b      %b        %b",
                 $time, clk, rst, coin, state, dispense, chg5);
    end

endmodule
