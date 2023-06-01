module segment_display_tb;

  reg clk;
  reg rst;
  wire [6:0] segment;

  segment_display dut (
    .clk(clk),
    .rst(rst),
    .segment(segment)
  );

  // Clock generation
  always #5 clk = ~clk;

  initial begin
	$dumpfile("segment.vcd");
	$dumpvars();

    clk = 0;
    rst = 1;
    #10 rst = 0; // De-assert reset after 10 time units

    // Wait for 50 time units to observe the count
    #500 $finish; // Terminate the simulation
  end

  always @(posedge clk) begin
    $display("Segment: %b", segment);
  end

endmodule

