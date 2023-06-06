module brightled_tb;
  reg clk;
  reg rst;
  reg button_plus;
  reg button_minus;
  wire led;
  
  brightled dut (
    .clk(clk),
    .rst(rst),
    .button_plus(button_plus),
    .button_minus(button_minus),
    .led(led)
  );

  initial begin
    clk = 0;
    rst = 1;
    button_plus = 0;
    button_minus = 0;
    #5 rst = 0; // Assert reset for 5 time units
    #200 button_plus = 1;
    #500 $finish; // Finish simulation after 50 time units
  end

  always begin
    #1 clk = ~clk; // Toggle clock every 5 time units
  end

  initial begin
    $dumpfile("brightled_test.vcd");
    $dumpvars();
    $monitor("clk = %b, rst = %b, led = %b", clk, rst, led);
  end

endmodule

