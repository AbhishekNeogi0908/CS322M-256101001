module master_fsm(
    input wire clk,
    input wire rst,
    input wire ack,
    output reg req,
    output reg [7:0] data,
    output reg done
);

    reg [2:0] state, next_state;
    reg [1:0] byte_cnt;

    localparam IDLE        = 3'd0,
               SEND_REQ    = 3'd1,
               WAIT_ACK    = 3'd2,
               DROP_REQ    = 3'd3,
               WAIT_ACK_LOW= 3'd4,
               CHECK_COUNT = 3'd5,
               DONE_STATE  = 3'd6;

    // State register
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            state <= IDLE;
            byte_cnt <= 0;
        end else begin
            state <= next_state;
            if (state == CHECK_COUNT && ack == 0 && byte_cnt < 3)
                byte_cnt <= byte_cnt + 1;
        end
    end

    // Next-state logic
    always @(*) begin
        next_state = state;
        case (state)
            IDLE:        next_state = SEND_REQ;
            SEND_REQ:    next_state = WAIT_ACK;
            WAIT_ACK:    if (ack) next_state = DROP_REQ;
            DROP_REQ:    next_state = WAIT_ACK_LOW;
            WAIT_ACK_LOW:if (!ack) next_state = CHECK_COUNT;
            CHECK_COUNT: if (byte_cnt == 3) next_state = DONE_STATE;
                         else next_state = SEND_REQ;
            DONE_STATE:  next_state = DONE_STATE;
        endcase
    end

    // Output logic
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            req <= 0; data <= 0; done <= 0;
        end else begin
            case (next_state)
                SEND_REQ: begin
                    req <= 1;
                    data <= byte_cnt; // test: send 0,1,2,3
                    done <= 0;
                end
                DROP_REQ: req <= 0;
                DONE_STATE: done <= 1;
                default: done <= 0;
            endcase
        end
    end

endmodule
