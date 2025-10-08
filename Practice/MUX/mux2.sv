`timescale 1ns/1ps
// `default_nettype none
module mux2(
    input logic a , b , sel,
    output logic y
);

always_comb begin
    y = sel ? b:a;
end

endmodule

// `default_nettype wire






