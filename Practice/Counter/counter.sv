`timescale 1ns/1ps


module counter #(
    parameter WIDTH=8
)(
    input logic clk,
    input logic rst_n,
    input logic en,
    input logic up,
    output logic [WIDTH-1:0] q
);

always_ff @(posedge clk or posedge rst_n) begin
    if(rst_n) q<='0;
    else if(en) q<= up ? (q+1'b1):(q-1'b1);
end

endmodule