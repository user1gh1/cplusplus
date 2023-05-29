module blink4_tb();
  reg clk;
  reg rst;
  wire led1;
  wire led2;
  wire led3;
  wire led4;

  blink4 dut (
    .clk(clk),
    .rst(rst),
    .led1(led1),
    .led2(led2),
    .led3(led3),
    .led4(led4)
  );

  always #5 clk = ~clk;

  initial begin
    $dumpfile("blink4_tb.vcd");
    $dumpvars();
    clk = 1'b0;
    rst = 1'b1;
    #10 rst = 1'b0;
    #500;
    #100000 $finish;
  end

endmodule

