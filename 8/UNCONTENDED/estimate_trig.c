



static void naked_placement_in_RAM0_sine(void) __naked
{
__asm
    SECTION BANK_00
__endasm;
}
double_t _sine(double_t xx) {
  //const float P = 0.225;
  const double_t A = 7.5888;//A = 16 * sqrt(P);
  const double_t B = 1.634;//B = (1 - P) / sqrt(P);
  double_t yy = xx / 6.28;
  yy = yy - floor(yy + 0.5);
  yy = A * yy * (0.5 - ABS(yy));
  return yy * (B + ABS(yy));
  //need to convert float to half_t by using math 16
}


static void naked_placement_in_RAM0_cosine(void) __naked
{
__asm
    SECTION BANK_00
__endasm;
}
double_t _cosine(double_t xx) {
  return _sine(xx + M_PI / 2);
  //return _sine(xx + M_PI >> 1);
  //need to convert float to half_t by using math 16
}

/* End of estimate_trig.c */
