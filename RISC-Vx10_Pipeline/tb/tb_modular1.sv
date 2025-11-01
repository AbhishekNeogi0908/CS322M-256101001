`timescale 1ns/1ps
module tb_modular;
    
    reg clk;
    reg rst;

    // instantiate the modular DUT
    riscvpipeline uut(.clk(clk), .rst(rst));

    // Clock generator
    initial begin
        clk = 0;
        forever #5 clk = ~clk; // 10 ns 
    end

    initial begin
        $dumpfile("pipeline.vcd");
        $dumpvars(0, uut);

        rst = 1;
        $display("TB: reset asserted at time=%0t", $time);

        
        @(posedge clk);
        @(posedge clk);

        // release reset
        #1;
        rst = 0;
        $display("TB: releasing reset at time=%0t", $time);

        // Initialize entire imem to NOP and load program after reset
        for (integer i = 0; i < 512; i = i + 1) begin
            uut.imem[i] = 32'h00000013; // NOP
        end
        $readmemh("tests/rvx10_pipeline.hex", uut.imem);

        // Initialize entire dmem to 0 (simple_ram resized to 1024 words)
        for (integer i = 0; i < 1024; i = i + 1) begin
            uut.dmem_inst.mem[i] = 32'd0;
        end

        
        #2000;// run time

        
        if (uut.dmem_inst.mem[100 >> 2] == 25) 
        	$display("TEST PASSED: dmem[100] == 25");
        else
        	$display("TEST FAILED: dmem[100] = %0d (expected 25)", uut.dmem_inst.mem[100 >> 2]);

        $display("cycle_count = %0d", uut.cycle_count);
        $display("instr_retired = %0d", uut.instr_retired);

        // CPI comparisons
        real measured_cpi;
        real single_cycle_cpi; // non-pipelined (assume 5-stage single-cycle takes 5 cycles per instruction)
        real ideal_pipelined_cpi; // ideal pipeline CPI = 1

        if (uut.instr_retired > 0) begin
            measured_cpi = $itor(uut.cycle_count) / $itor(uut.instr_retired);
        end else begin
            measured_cpi = 0.0;
        end

        single_cycle_cpi = 5.0;
        ideal_pipelined_cpi = 1.0;

        $display("Measured CPI = %0.3f", measured_cpi);
        $display("Single-cycle baseline CPI = %0.3f", single_cycle_cpi);
        $display("Ideal pipelined CPI = %0.3f", ideal_pipelined_cpi);

        if (measured_cpi > 0) begin
            $display("%s compared to single-cycle: %0.2f%% of cycles per instruction", (measured_cpi < single_cycle_cpi)?"Better":"Worse", (measured_cpi / single_cycle_cpi) * 100.0);
            $display("%s compared to ideal pipeline: %0.2f CPI-overhead", (measured_cpi <= ideal_pipelined_cpi)?"Equal/Better":"Slower", measured_cpi - ideal_pipelined_cpi);
        end
        $finish;
    end

    always @(posedge clk) begin
        if (!rst)
            $display("TB_MON: time=%0t cycle=%0d imem_addr=%0h ifid_instr=%h retired=%0d",
                     $time, uut.cycle_count, uut.imem_addr, uut.ifid_instr, uut.instr_retired);
    end
endmodule
