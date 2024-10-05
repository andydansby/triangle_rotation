

#define ABS(N) ((N<0)?(-N):(N))


float _sine(float xx)
{
	//http://devmaster.net/posts/9648/fast-and-accurate-sine-cosine
    //this routine was found by user Smile, don't know where
    //the algorithm comes from
    //pretty fast

	//const float P = 0.224008178776;
    const float P = 0.225;
    const float A = 7.5888;//A = 16 * sqrt(P);
    const float B = 1.634;//B = (1 - P) / sqrt(P);
    float yy = xx / 6.28;

    yy = yy - floor(yy + 0.5);
	//yy = yy - floor(yy + 0.5);
	yy = A * yy * (0.5 - ABS(yy));

	return yy * (B + ABS(yy));
}


float _cosine (float xx)
{
	return _sine(xx + M_PI / 2);
}