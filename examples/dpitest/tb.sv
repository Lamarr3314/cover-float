module tb; import coverfloat_pkg::*;

    float32_t a, b, c, y;

    intermResult_t preRound;

    initial begin 

        a.val = 32'h 3F868A01;
        b.val = 32'h 3F8F8141;

        y = f32_mul(a, b);

        softfloat_getIntermResults(preRound);

        #5;

        $display("Test case 1:");
        $display("0x%h * 0x%h = 0x%h", a.val, b.val, y.val);
        $display("with intermediate result:");
        $display("Sign=%b   exp=%d   sig=%b", preRound.sign, preRound.exp, preRound.sig64);


    end

endmodule