module counter #(
	parameter COUNT = 4
) (
	input clk,
	input reset,
	output reg out_pulse
);

reg [COUNT-1:0]cnt = {COUNT{1'b0}};


always @ (posedge clk) begin
	if (reset) begin
		out_pulse <= 1'b1;
		cnt <= 1'b0;
	end
	if (cnt == COUNT) begin
		out_pulse <= 1'b1;
		cnt <= 1'b0;
	end
	else begin
		cnt <= cnt + 1'b1;
		out_pulse <= 1'b0;
	end
end

endmodule


		
	
