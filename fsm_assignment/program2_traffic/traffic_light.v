module traffic_light(
    input wire clk,
    input wire rst,   // sync active-high
    input wire tick,  // 1 Hz pulse
    output reg ns_g, ns_y, ns_r, //these are the traffic lights(basically outputs)
    output reg ew_g, ew_y, ew_r //these are the traffic lights(basically outputs)
);

    // State encoding
    parameter S0 = 2'b00;  // NS Green, EW Red
    parameter S1 = 2'b01;  // NS Yellow, EW Red
    parameter S2 = 2'b10;  // EW Green, NS Red
    parameter S3 = 2'b11;  // EW Yellow, NS Red

    reg [1:0] state, next_state;
    reg [3:0] tick_count;  // up to 5 ticks

    // State + counter update
    always @(posedge clk) begin
        if (rst) begin
            state <= S0;
            tick_count <= 0;
        end
        else if (tick) begin
            if ((state==S0 && tick_count==5) || 
                (state==S1 && tick_count==2) || 
                (state==S2 && tick_count==5) || 
                (state==S3 && tick_count==2)) begin
                state <= next_state;
                tick_count <= 0;
            end
            else begin
                tick_count <= tick_count + 1;
            end
        end
    end

    // Next state logic
    always @(*) begin
        case (state)
            S0: next_state = S1;
            S1: next_state = S2;
            S2: next_state = S3;
            S3: next_state = S0;
            default: next_state = S0;
        endcase
    end

    // Output logic (Moore)
    always @(*) begin
        // default
        ns_g=0; ns_y=0; ns_r=0;
        ew_g=0; ew_y=0; ew_r=0;

        case (state)
            S0: begin ns_g=1; ew_r=1; end
            S1: begin ns_y=1; ew_r=1; end
            S2: begin ew_g=1; ns_r=1; end
            S3: begin ew_y=1; ns_r=1; end
        endcase
    end

endmodule
