module brightled (
	input clk, 
	input rst,
	input button_plus,
	input button_minus,
	output reg led
);
	reg [31:0] count = 0;
	reg [31:0] bright = 50;

	wire b_plus_out;
    wire b_minus_out;
	
	debounce debplus (
	  .clk(clk),
	  .rst(rst),
	  .button(button_plus),
	  .button_out(b_plus_out)
	);

	debounce debminus (
	  .clk(clk),
	  .rst(rst),
	  .button(button_minus),
	  .button_out(b_minus_out)
	);
	 
	always @(posedge clk) begin
		if (rst) 
		begin  
			led <= 1'b0;
			count <= 0;
		end
		else if (b_plus_out)
				bright <= bright + 50;
		else if (b_minus_out)
				bright <= bright - 50;
		else
		begin
			if ( count == bright )
			begin
				count <= 0;
				led <= 1'b1;
			end
			else 
			begin 
				count <= count + 1;
				led <= 1'b0;
			end
		end
	end

endmodule


