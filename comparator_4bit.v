module comparator_4bit(
    input [3:0] A,
    input [3:0] B,
    output C
);

assign C = (A==B) ? 1:0; // C is High if A == B


endmodule

