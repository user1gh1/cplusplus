module testbench();
  parameter SIZE = 16;

  reg [SIZE-1:0] a;
  reg [SIZE-1:0] b;
  wire [SIZE:0] s;

  add8 #(SIZE) add8_test(.a(a), .b(b), .sum(s));

  initial begin
    $dumpfile("anybitsum_test.vcd");
    $dumpvars();  
    // Binary example
    a = {SIZE{1'b1}}; // Set 'a' to all 1's
    b = {SIZE{1'b1}}; // Set 'b' to all 1's
    #1;
    $display("a = %b, b = %b, sum = %b", a, b, s);

    // Decimal example
    a = 123; 
    b = 87;  
    #1;
    $display("a=%d, b=%d, sum=%d", a, b, s);

    $finish;
  end
endmodule
    
