module segment_display (
  input clk,
  input rst,
  input button_plus,
  input button_minus,
  output reg [6:0] segment
);
  reg [3:0] number;
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
    if (rst) begin
      number <= 4'b0000;
      segment <= 7'b1111111;
    end
    else begin
      if (b_plus_out) //&& number != 4'b1001)
        number <= number + 4'b0001;
      else if (b_minus_out) //&& number != 4'b0000)
        number <= number - 4'b0001;
    end
  end

  always @(number) begin
    case(number)
      4'b0000: segment <= 7'b0000001;
      4'b0001: segment <= 7'b1001111;
      4'b0010: segment <= 7'b0010010;
      4'b0011: segment <= 7'b0000110;
      4'b0100: segment <= 7'b1001100;
      4'b0101: segment <= 7'b0100100;
      4'b0110: segment <= 7'b0100000;
      4'b0111: segment <= 7'b0001111;
      4'b1000: segment <= 7'b0000000;
      4'b1001: segment <= 7'b0000100;
      default: segment <= 7'b1111111;
    endcase
  end
endmodule
