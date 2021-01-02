The program in this folder is meant to illustrate the structure of data types in memory including char, char[], int, and float. 

A useful tool in visualizing the memory is to use Microsoft Visual Studio. 

    This IDE contains a useful feature in which you can see the byte stored at each hexadecimal address in memory. 
    To access it,
        1.) hover over the "Debug" drop down in the tool bar.
        2.) Select "Windows".
        3.) In the "Windows" drop down, select "Memory" near the bottom.
        4.) You can select up to four memory windows to view whatever hexadecimal address you may want to view. 
        5.) NOTE: printing an address in the program's current format will yield the last 6 digits of the address. The full address
            is 8 hexadecimal digits with an "0x" and 2 leading zero's in this case. Just keep that in mind in case you get 
            an incorrect address when entering a value into the search bar of the memory window.  
Compilation is as follows: 
    In the directory that the file resides in, run the following command in the terminal: 
        gcc memory_structure.c -o (whatever name you would like to call the executable)

