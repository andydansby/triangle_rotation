
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//UNCONTENDED RAM


void use_random_number_generator (int maxNumber, int minNumber)
{
    xorshift_prng ();
    random_number_16 = random_number_16 % (maxNumber + 1 - minNumber) + minNumber;
    //printf ("random number = %d\n", random_number_16);
    //return random_number_16;
}

#endif

