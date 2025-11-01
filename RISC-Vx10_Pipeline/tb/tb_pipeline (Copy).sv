`timescale 1ns/1ps
module tb;
   
    reg clk;
    reg rst;

    riscvpipeline uut(.clk(clk), .rst(rst));

    initial begin
        clk = 0;
        forever #5 clk = ~clk; // 10 ns period
    end
    
  
    initial begin
        
        $dumpfile("dump.vcd");
        $dumpvars(0, uut);

        // assert reset
        rst = 1;
        $display("TB: reset asserted at time=%0t", $time);

        // Wait for 2 full clock cycles while reset is high to ensures all registers are properly reset.
        @(posedge clk);
        @(posedge clk);

        // De-assert reset *between* clock edges (1ns after the posedge)
        #1;
        $display("TB: releasing reset at time=%0t", $time);
        rst = 0;

        for (integer i = 0; i < 64; i = i + 1) begin
            uut.imem[i] = 32'h00000013; // NOP
        end
        $readmemh("tests/rvx10_pipeline.hex", uut.imem);

        // Initialize dmem
        for (integer i = 0; i < 64; i = i + 1) begin
            uut.dmem[i] = 32'd0;
        end

        #2000;

        // check memory[100] (word index 100/4 = 25)
    if (uut.dmem[100 >> 2] == 25) 
    	$display("TEST PASSED: dmem[100] == 25");
    else 
    	$display("TEST FAILED: dmem[100] = %0d (expected 25)", uut.dmem[100 >> 2]);

        // Check performance counters
        $display("cycle_count = %0d", uut.cycle_count);
        $display("instr_retired = %0d", uut.instr_retired);
        if (uut.instr_retired != 0) $display("CPI = %0f", $itor(uut.cycle_count) / $itor(uut.instr_retired));

        $finish;
    end

    // Optional monitor
    always @(posedge clk) begin
        if (!rst)
            $display("TB_MON: time=%0t cycle=%0d PC=%0h ifid_instr=%h retired=%0d",
                     $time, uut.cycle_count, uut.PC, uut.ifid_instr, uut.instr_retired);
    end
    
endmodule
