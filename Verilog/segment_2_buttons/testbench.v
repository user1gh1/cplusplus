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

  
  always #5 clk = ~clk;

  initial begin
	$dumpfile("segment2buttons.vcd");
	$dumpvars();
    clk = 0;
    rst = 1;
    button_plus = 0;
    button_minus = 0;
    #10 rst = 0; 


    #15 button_plus = 1; 
    #50 button_plus = 0;   
    #15 button_plus = 1; 
    #5 button_plus = 0;   
    #10 button_minus = 1; 
    #5 button_minus = 0;  
    #20 button_plus = 1;  
    #5 button_plus = 0;   


    #1000 $finish; 
  end

  always @(posedge clk) begin
    $display("Segment: %b", segment);
  end

endmodule

