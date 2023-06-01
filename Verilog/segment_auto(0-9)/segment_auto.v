module segment_display (
  input clk,
  input rst,
  output reg [6:0] segment
);  
	reg [3:0] number;
	wire pulse_out;  
  
  timer #(
    .WIDTH(32)
  ) cnt_i (
    .clk(clk),
    .rst(rst),
    .limit(1),
    .pulse_out(pulse_out)
  );  

  always @(posedge clk) begin
    if (rst) begin
      number <= 4'b0000;
      segment <= 7'b1111111;
    end
    else if (pulse_out) begin
      if (number == 4'b1001)
        number <= 4'b0000;
      else
        number <= number + 4'b0001;
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
