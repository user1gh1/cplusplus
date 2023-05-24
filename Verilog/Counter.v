module counter (
	input clk,
	input reset,
	output reg out_pulse
);

reg [3:0]cnt = 4'b0000;


always @ (posedge clk or posedge reset ) begin
	if (cnt == 4'b0100) begin
		out_pulse <= 1'b1;
		cnt <= 1'b0;
	end
	else begin
		cnt <= cnt + 1'b1;
		out_pulse <= 1'b0;
	end
end

endmodule

module testbench();
	reg clk;
	reg reset;
	wire out;
	wire[3:0] cnt;
	//wire reset = 0;
	counter counter_test (.clk(clk), .reset(reset), .out_pulse(out));
	
	initial begin
		$dumpfile("counter_test.vcd");
		$dumpvars();
		clk = 1'b0;
		reset = 1'b0;
		#50 $finish;
	end

	always begin
		#1 clk = ~clk;
	end

	always @* begin
		$display ("time=%0t clk=%bclk out_pulse=%b cnt=%d", $time, clk, out, cnt);

	end

	assign cnt = counter_test.cnt;

endmodule
		
	
