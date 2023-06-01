module segment_display_tb;

  reg clk;
  reg rst;
  reg button_plus;
  reg button_minus;
  wire [6:0] segment;

  segment_display dut (
    .clk(clk),
    .rst(rst),
    .button_plus(button_plus),
    .button_minus(button_minus),
    .segment(segment)
  );

  // Clock generation
  always #5 clk = ~clk;

  initial begin
    clk = 0;
    rst = 1;
    button_plus = 0;
    button_minus = 0;
    #10 rst = 0; // De-assert reset after 10 time units

    // Simulate button presses
    #15 button_plus = 1;  // Press button_plus
    #5 button_plus = 0;   // Release button_plus
    #10 button_minus = 1; // Press button_minus
    #5 button_minus = 0;  // Release button_minus
    #20 button_plus = 1;  // Press button_plus again
    #5 button_plus = 0;   // Release button_plus

    // Wait for 100 time units to observe the segment values
    #100 $finish; // Terminate the simulation
  end

  always @(posedge clk) begin
    $display("Segment: %b", segment);
  end

endmodule

