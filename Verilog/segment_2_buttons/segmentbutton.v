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
      segment <= 7'b0000000;
    end
    else begin
      if (button_plus && !button_minus && number != 4'b1001)
        number <= number + 1;
      else if (button_minus && !button_plus && number != 4'b0000)
        number <= number - 1;
    end
  end

  always @(number) begin
    case(number)
      4'b0000: segment <= 7'b1000000;
      4'b0001: segment <= 7'b1111001;
      4'b0010: segment <= 7'b0100100;
      4'b0011: segment <= 7'b0110000;
      4'b0100: segment <= 7'b0011001;
      4'b0101: segment <= 7'b0010010;
      4'b0110: segment <= 7'b0000010;
      4'b0111: segment <= 7'b1111000;
      4'b1000: segment <= 7'b0000000;
      4'b1001: segment <= 7'b0011000;
      default: segment <= 7'b0000000;
    endcase
  end
endmodule 

