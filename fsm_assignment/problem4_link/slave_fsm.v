module slave_fsm(
    input wire clk,
    input wire rst,
    input wire req,
    input wire [7:0] data_in,
    output reg ack,
    output reg [7:0] last_byte
);

    reg [2:0] state, next_state;

    localparam IDLE        = 3'd0,
               LATCH       = 3'd1,
               HOLD1       = 3'd2,
               HOLD2       = 3'd3,
               WAIT_REQ_LOW= 3'd4;

    // State register
    always @(posedge clk or posedge rst) begin
        if (rst) state <= IDLE;
        else state <= next_state;
    end

    // Next state logic
    always @(*) begin
        next_state = state;
        case (state)
            IDLE:        if (req) next_state = LATCH;
            LATCH:       next_state = HOLD1;
            HOLD1:       next_state = HOLD2;
            HOLD2:       next_state = WAIT_REQ_LOW;
            WAIT_REQ_LOW:if (!req) next_state = IDLE;
        endcase
    end

    // Output logic
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            ack <= 0; last_byte <= 0;
        end else begin
            case (next_state)
                LATCH: begin
                    last_byte <= data_in;
                    ack <= 1;
                end
                HOLD1, HOLD2: ack <= 1;
                WAIT_REQ_LOW: if (!req) ack <= 0;
            endcase
        end
    end

endmodule
