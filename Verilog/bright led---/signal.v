module Signal_Controller (
    input wire clk,
    input wire res,
    input wire button1,
    input wire button2,
    output reg signal
);

reg [6:0] count;
reg [6:0] calibrate_count;
reg [6:0] duration;

always @(posedge clk or posedge res) begin
    if (res)
        count <= 7'b0; // Reset count to 0
    else if (button1)
        count <= count + 1; // Increment count
    else if (button2)
        count <= count - 1; // Decrement count
end

always @(posedge clk or posedge res) begin
    if (res)
        duration <= 7'b0; // Reset duration to 0
    else if (button1 || button2)
        duration <= duration + 1; // Increment duration
end

always @(posedge clk) begin
    if (duration >= 7'b1111101) // 125 in decimal (approximately 1 second)
        calibrate_count <= count;
end

always @(posedge clk or posedge res) begin
    if (res)
        signal <= 1'b0; // Reset signal to 0
    else if (duration >= 7'b1111101) // 125 in decimal (approximately 1 second)
        signal <= calibrate_count[0]; // Calibrate signal to the least significant bit of calibrate_count
end

endmodule

module Signal_Controller_tb;

reg clk, res, button1, button2;
wire signal;

Signal_Controller DUT (
    .clk(clk),
    .res(res),
    .button1(button1),
    .button2(button2),
    .signal(signal)
);

initial begin
    $monitor("Signal: %b", signal);
    clk = 1'b0;
    forever #5 clk = ~clk;
end

initial begin
$dumpfile("signal.vcd");
$dumpvars();

    res = 1'b1;
    button1 = 1'b0;
    button2 = 1'b0;
    #10 res = 1'b0;
    #20 button1 = 1'b1;
    #30 button1 = 1'b0;
    #20 button2 = 1'b1;
    #40 button2 = 1'b0;
    #100 $finish;
end

endmodule

