module testbench();
	parameter COUNT = 4;
	reg clk;
	reg reset;
	wire out;
	wire[COUNT-1:0] cnt;
	counter #(COUNT) counter_test (.clk(clk), .reset(reset), .out_pulse(out));

	assign cnt = counter_test.cnt;

	always begin
		#1 clk = ~clk;
	end
	
	initial begin
		$dumpfile("counter_test.vcd");
		$dumpvars();
		clk = 1'b0;
		reset = 1'b0;
		#50 $finish;
	end


	always @* begin
		$display ("clk=%bclk out_pulse=%b cnt=%d", clk, out, cnt);

	end


endmodule
