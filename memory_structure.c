// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdbool.h>
char array1[] = "cat";
char array2[] = "dog";


//char's are always unsigned by default.
char singlechar = 'f';
char singlechar2 = 'e';
double exampledouble = 1.125;
float examplefloat = 17.125;
//float the1 = 4.3;
char singlechar3 = 'r';

int exampleinteger1 = 9;
int exampleinteger2 = 10;
int exampleinteger3 = 18;

void* generic_pointer;

void binary_conversion_of_char(char c);
void memory_structure_of_float(float examplefloat);




int main() {
    printf("The following terminal statements are meant to illustrate the structure of memory for various basic data types porttrayed in the c language.\n\n");
    /*characters alone take up one byte of space in memory.
    this means that it takes two hexadecimal characters to represent it in a hexadecimal format.
    strings, at least in c, are just an array of characters. that's how they are actually represented in c. 
    see above the two "strings" declared as array1 and array2.
    */

    //NOTE: a key difference in a character and a character array sequance is that in memory
    //the "string" ends with a null terminator which also uses an entire byte.

    printf("Below is an example of a character's representation in memory...\n\n");
    printf("    Index in memory of singlechar is: 0x00%x\n", &singlechar);//supposedly holds one byte 
    printf("    Hexadecimal representation of singlechar '%c' is: 0x%x\n\n", singlechar, singlechar);
    printf("    Binary representation of the ascii character above is: ");
    binary_conversion_of_char(singlechar);
    printf("\n\n");
    printf("Furthermore, the following is an example of an array's representation in memory...\n\n");
    printf("    Beginning index in memory of array1 is: 0x00%x\n", array1);//one byte per letter since it is stored as an ascii binary format.
                                                                        
    //the data beginning at this address can be retrieved and presented in many different
    //ways depending on the format specifier. 
    
    //NOTE: The "sizeof" operator returns the size of the item in bytes. Since the characters take up one byte each in memory, this will 
    //be suitable for our for loop to iterate through the string.

    printf("    the hexadecimal memory representation of the memory of array1 is: \n");
    for(int i = 0; i < sizeof(array1); i++){
        printf("    address 0x00%x contains 0x%x which is the hexadecimal representation of the character: ", &array1[i], array1[i]);
        if (array1[i] == NULL) {
            printf("NULL");
        }
        printf("%c in memory\n", array1[i]);
    }
    /*
        Integers are also held in hexadecimal in memory however their formatting is a bit different.
        The hexadecimal numbers directly represents the integer value instead of representing the ASCII
        value of the number(s). 

        One of the examples seen below is the integer 10. 10 is the same value as 0xA in hexadecimal, 
        therefore, the binary sequence held in memory will translate to A in hexadecimal.

        Another hypothetical example would be 18. 

        Since hexadecimal rolls over at 15, the next left placeholder in the hexadecimal sequence will 
        be incremented by 1. Therefore, when the value get to 15, the representation in hexadecimal will 
        be: 0x0F, but then when the value becomes 16, the power is rolled over into the next left placeholder.
        0x10. Continuing with the count, we can see that the number is represented in memory as: 0x12.
    */

    printf("\n\nBelow is an example of integer memory structure: \n\n");

    printf("\n    Index in memory of exampleinteger1 is: 0x00%x\n", &exampleinteger1);
    printf("    Index in memory of exampleinteger2 is: 0x00%x\n", &exampleinteger2);
    printf("    Value held in memory of exampleinteger1 is: 0x%x\n", exampleinteger1);
    printf("    Value held in memory of exampleinteger2 is: 0x%x\n", exampleinteger2);
    printf("    Index in memory of exampleinteger3 is: 0x%x\n", &exampleinteger3);
    printf("    Value held in memory of exampleinteger3 is: 0x%x\n", exampleinteger3);


    /*double and floating point data types are quite a bit more complex. 

        NOTE: The key difference between double and float is that a double takes up 8 bytes in 
        memory while a float takes up four.(true?)
        
        The sequence of bits stored in these 32 bits (in this case for a double) 
        is as follows:

            sign bit: 1, exponent bits: 8, mantissa: 23

            Summarizing as briefly as possible, the mantissa holds the actual value in binary
            from the fractional side (where each bit further to the right represents a smaller 
            and smaller fraction of one), the exponent holds the number of decimal places that
            will have to be shifted, and the sign bit indicates, well, the sign of the value.

            A much more in depth explanation can be seen here: https://www.cs.cornell.edu/~tomf/notes/cps104/floating.html 

            
    */ 

    printf("\n\nBelow is an example of floating point memory structure: \n\n");


    printf("    The address of the float 'examplefloat'  in memory is: 0x00%x\n", &examplefloat);
    printf("    The vlaue in memory of 'examplefloat' is: %x\n");//may have to calculate manually in order to show it in memory.
    
    //The below function displays the floating point number in binary representation. 
    memory_structure_of_float(examplefloat);

    /*
        Here's where things get wonky. Now that we have the binary representation, we have to format it in such a way that we can meaningfully store 
        it in memory since we can't store the decimal point. (among other reasons.)

        NOTE: I would highly recommend visiting the link pasted above for lots of pictures and a well worded explanation of the process. 
            It could potentially take many paragraphs to explain this method without visual aids. 

        In our example: 10001.001 --> 1.0001001 exponent is 4
        
        127 + 4 = 131 --> 10000011

        So, 10000011 will fill the exponent field. 

        The mantissa will now hold 0001001000...all the way to 23 bits length.
        So the final result will be: 
            0     10000011    00010010000000000000000
          Sign    Exponent          Mantissa

          0100 --> 0x4, 0001 --> 0x1, 1000 --> 0x8, 1001 --> 0x9,  0000 --> 0x0, 0000 --> 0x0, 0000 --> 0x0, 0000 --> 0x0,

          So, the memory content in hex should be: 0x41890000   

          NOTE: In terms of memory storage, recall the (what) endian storage method in which ...
    */



    /*
        Below is an example of generic pointers. generic pointers are declared as void pointers because 
        they can be used to point to and dereference the address of any type of pointer, an example of which is 
        illustrated below.

        NOTE: You must cast the pointer as the data type pointer that it is pointing to before you dereference that address
        in order to use the specific format specifier for that variable.

        
        See example below. 
    */
    printf("\n\nBelow is an example of how generic pointers work with memory addresses of all data types.\n\n");

    generic_pointer = &singlechar;
    printf("    Generic pointer contains the address of singlchar which is: %x\n", generic_pointer);
    printf("    Dereferencing the generic pointer to display the character at that address yields: %c\n", *(char *)generic_pointer);
    
    generic_pointer = &exampleinteger1;
    printf("    Generic pointer now contains the address of somethingelse which is: %x\n", generic_pointer);
    printf("    Dereferencing the generic pointer to display the integer at that address yields: %d\n\n\n", *(int*)generic_pointer);
    
    
}


/*
    The function below is meant to express the binary 
    representation of the ascii character according to its table.
*/

void binary_conversion_of_char(char c) {
    int def = (int)c;
    int binary_exponent_value = 128;//this is the highest value in the 8 digit representation
                                    //of the ascii value.

    while (binary_exponent_value != 0) {
        if (def - binary_exponent_value >= 0) {
            printf("1");
            def = def - binary_exponent_value;
            binary_exponent_value = binary_exponent_value / 2;
        }
        else {
            printf("0");
            binary_exponent_value = binary_exponent_value / 2;
        }
    }

}

/*
    The function below is meant to express the binary representation of a floating point data type.
    NOTE: The key difference between a float and a double is that a double takes up 8 bytes in memory 
    in order to have more precision while a float only takes up four bytes. 

    expand on that a little bit.
*/

void memory_structure_of_float(float examplefloat) {    
    //first, we should cast the double as an int in order to get the whole integer without the fraction. 
    int whole_number = (int)examplefloat;
    float remainder = examplefloat - whole_number;//I know we are using a float again here but just trust the process.
    printf("    result of truncated float is: %d\n", whole_number);
    printf("    The remainder is: %f\n", remainder);

    printf("    The binary representation of the float is: \n       ");
    
    
    //while power of two is less than whole_number, increase the number by a power of 2. 
    int power_of_two = 1; //for two to the power of zero.
    bool permissive = true;
    while (permissive){
        if (power_of_two * 2 > whole_number)
            break;
        power_of_two = power_of_two * 2;
    }
    //printf("power of two is: %d\n", power_of_two);

    //now we are printing out the integer number in binary representation. 
    while (power_of_two != 0) {
        if (whole_number - power_of_two >= 0) {
            printf("1");
            whole_number = whole_number - power_of_two;
            power_of_two = power_of_two / 2;
        }
        else {
            printf("0");
            power_of_two = power_of_two / 2;
        }
    }
    printf(".");
    
    //printf("the remainder is: %f\n", remainder);
    float multiplier = remainder;
    while (multiplier  != 0 && multiplier != 1) {
        //this is where we determine the binary sequence for the fraction of the float. 
        multiplier = multiplier * 2;//we are multiplying by two because that is the base of the numbering system we are converting to. 
        if (multiplier > 1) {
            multiplier = multiplier - 1;
        }

        //printf("multiplier is now: %f\n", multiplier);
        if (multiplier < 1) {
            printf("0");
        }
        else {
            printf("1");
        }

        
    }
    printf("\n");

}

