module vending_mealy(
    input  wire       clk,
    input  wire       rst,        // synchronous, active-high reset
    input  wire [1:0] coin,       // 01=5, 10=10, 00=idle
    output reg        dispense,   // 1-cycle pulse
    output reg        chg5,       // 1-cycle pulse when returning 5
    output reg [1:0]  state       // current FSM state
);

    // State encoding (total = 0,5,10,15)
    parameter S0  = 2'b00;
    parameter S5  = 2'b01;
    parameter S10 = 2'b10;
    parameter S15 = 2'b11;

    reg [1:0] current_state, next_state;

    // Sequential state update
    always @(posedge clk) begin
        if (rst)
            current_state <= S0;
        else
            current_state <= next_state;
    end

    // Combinational next state + outputs (Mealy)
    always @(*) begin
        // defaults
        next_state = current_state;
        dispense   = 0;
        chg5       = 0;
        state      = current_state;

        case (current_state)
            S0: begin
                if (coin == 2'b01)      next_state = S5;   // +5
                else if (coin == 2'b10) next_state = S10;  // +10
            end

            S5: begin
                if (coin == 2'b01)      next_state = S10;  // +5
                else if (coin == 2'b10) next_state = S15;  // +10
            end

            S10: begin
                if (coin == 2'b01)      next_state = S15;  // +5
                else if (coin == 2'b10) begin              // +10 = 20
                    dispense   = 1;
                    next_state = S0;
                end
            end

            S15: begin
                if (coin == 2'b01) begin                   // +5 = 20
                    dispense   = 1;
                    next_state = S0;
                end
                else if (coin == 2'b10) begin              // +10 = 25
                    dispense   = 1;
                    chg5       = 1;
                    next_state = S0;
                end
            end
        endcase
    end

endmodule
