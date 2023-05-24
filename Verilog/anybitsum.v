module add (
	input a,
	input b,
	input carry_in,
	output sum,
	output carry_out
);

assign sum = (a ^ b) ^ carry_in;
assign carry_out = (a & b) | ((a ^ b) & carry_in);

endmodule

module add8 #(
  parameter SIZE = 8
) (
  input [SIZE-1:0] a,
  input [SIZE-1:0] b,
  output [SIZE:0] sum
);
  wire [SIZE-1:0] c;
  
  genvar i;
  generate
    for (i = 0; i < SIZE; i = i + 1) begin : adder_gen
      add add_inst (
        .a(a[i]),
        .b(b[i]),
        .carry_in(i == 0 ? 1'b0 : c[i-1]),
        .sum(sum[i]),
        .carry_out(c[i])
      );
    end
  endgenerate

  assign sum[SIZE] = c[SIZE-1];

endmodule
