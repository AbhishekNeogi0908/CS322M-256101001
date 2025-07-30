//AIM : Our aim is to create a simple comparator in verilog in which there are 2 binary single bit inputs . If A > B then C1 will be high, if A < B then C2 will be high and if A == B then C3 will be high.

module my_comparator(
    input A,
    input B,
    output C1,
    output C2,
    output C3
);

assign C1 = A & ~B; // C1 is High if :- A>B
assign C2 = ~A & B; // C2 is High if :- A<B
assign C3 = ~(A ^ B); //C3 is High if :- A==B

endmodule