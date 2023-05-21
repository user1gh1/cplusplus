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

module add8 (
	input [7:0]a, 
	input [7:0]b,
	output [7:0]sum
);
add add0 (.a(a[0]), .b(b[0]), .carry_in(1'b0),  .sum(sum[0]), .carry_out(c0));
add add1 (.a(a[1]), .b(b[1]), .carry_in(c0), .sum(sum[1]), .carry_out(c1));
add add2 (.a(a[2]), .b(b[2]), .carry_in(c1), .sum(sum[2]), .carry_out(c2));
add add3 (.a(a[3]), .b(b[3]), .carry_in(c2), .sum(sum[3]), .carry_out(c3));
add add4 (.a(a[4]), .b(b[4]), .carry_in(c3), .sum(sum[4]), .carry_out(c4));
add add5 (.a(a[5]), .b(b[5]), .carry_in(c4), .sum(sum[5]), .carry_out(c5));
add add6 (.a(a[6]), .b(b[6]), .carry_in(c5), .sum(sum[6]), .carry_out(c6));
add add7 (.a(a[7]), .b(b[7]), .carry_in(c6), .sum(sum[7]));

endmodule

module testbench();
	reg [7:0]a;
	reg [7:0]b;
	wire [7:0]s;
	add8 add8_test (.a(a), .b(b), .sum(s));
	initial	begin
		//binary example
		a = 8'b10110010; b = 8'b00001111; #1  $display("a = %b, b = %b, sum = %b", a, b, s);
		//decimal example
		a = 19; b = 14; #1  $display("a =%d, b =%d, sum =%d", a, b, s);
	end
endmodule

	
