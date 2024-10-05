

#define ABS(N) ((N<0)?(-N):(N))

half_t _sine(half_t xx) {
  const half_t P = 0.225;
  const half_t A = 7.5888;//A = 16 * sqrt(P);
  const half_t B = 1.634;//B = (1 - P) / sqrt(P);
  half_t yy = xx / 6.28;
  yy = yy - floor(yy + 0.5);
  yy = A * yy * (0.5 - ABS(yy));
  return yy * (B + ABS(yy));
}

half_t _cosine (half_t xx) {
  return _sine(xx + M_PI / 2);
  //return _sine(xx + M_PI >> 1);
}

/* End of estimate_trig.c */


