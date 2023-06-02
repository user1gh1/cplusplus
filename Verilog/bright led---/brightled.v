module LED_Controller (
    input wire reset,
    input wire bright_up,
    input wire bright_down,
    output reg led
);

reg [2:0] brightness;

always @ (posedge reset)
begin
    brightness <= 3'b000; // Initialize brightness to the lowest level
end

always @ (*)
begin
    if (reset)
        led <= 1'b0; // Reset LED to off state
    else if (bright_up && brightness < 3'b111)
        brightness <= brightness + 1; // Increase brightness by 1 level
    else if (bright_down && brightness > 3'b000)
        brightness <= brightness - 1; // Decrease brightness by 1 level
end

always @ (*)
begin
    if (brightness > 0)
        led <= 1'b1; // Turn on LED if brightness is greater than 0
    else
        led <= 1'b0; // Turn off LED if brightness is 0
end

endmodule


module LED_Controller_tb;

reg reset, bright_up, bright_down;
wire led;

LED_Controller DUT (
    .reset(reset),
    .bright_up(bright_up),
    .bright_down(bright_down),
    .led(led)
);
initial begin
	$dumpfile("bright_led.vcd");
	$dumpvars();
    reset = 1'b1;
    #10 reset = 1'b0;
    #20 bright_up = 1'b1;
    #20 bright_up = 1'b0;
    #20 bright_up = 1'b1;
    #20 bright_up = 1'b0;
    #20 bright_down = 1'b1;
    #20 bright_down = 1'b0;
    #20 bright_up = 1'b1;
    #20 bright_down = 1'b1;
    #20 reset = 1'b1;
    #10 reset = 1'b0;
    #20 bright_down = 1'b0;
    #20 $finish;
end
always @ (*) $monitor("LED: %b", led);
endmodule

