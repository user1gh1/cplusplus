module blink4 (
  input clk,
  input rst,
  output reg led1,
  output reg led2,
  output reg led3,
  output reg led4
);

  reg [1:0] state;
  wire pulse_out;

  timer #(
    .WIDTH(32)
  ) cnt_i (
    .clk(clk),
    .rst(rst),
    .limit(25),
    .pulse_out(pulse_out)
  );

  always @(posedge clk) begin
    if (rst) begin
      led1 <= 1'b0;
      led2 <= 1'b0;
      led3 <= 1'b0;
      led4 <= 1'b0;
      state <= 2'b00;
    end
    else if (pulse_out) begin
      case(state)
        2'b00: begin
          led1 <= ~led1;
          state <= 2'b01;
        end
        2'b01: begin
          led2 <= ~led2;
          state <= 2'b10;
        end
        2'b10: begin
          led3 <= ~led3;
          state <= 2'b11;
        end
        2'b11: begin
          led4 <= ~led4;
          state <= 2'b00;
        end
        default: state <= 2'b00;
      endcase
    end
  end

endmodule

