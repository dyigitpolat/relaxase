#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


// Enable ECB, CTR and CBC mode. Note this can be done before including aes.h or at compile-time.
// E.g. with GCC by using the -D flag: gcc -c aes.c -DCBC=0 -DCTR=1 -DECB=1
#define CBC 1
#define CTR 1
#define ECB 1

#include "aes.hpp"
#include "relaxase_client.hpp"

uint8_t key[] = { 0x60, 0x3d, 0xeb, 0x10, 0x15, 0xca, 0x71, 0xbe, 0x2b, 0x73, 0xae, 0xf0, 0x85, 0x7d, 0x77, 0x81,
                      0x1f, 0x35, 0x2c, 0x07, 0x3b, 0x61, 0x08, 0xd7, 0x2d, 0x98, 0x10, 0xa3, 0x09, 0x14, 0xdf, 0xf4 };

int count=0;

RelaxaseClient::RelaxaseClient()
{
   
} 

int RelaxaseClient:: file_access(string file_name)
{
   uint8_t input[1000000];
   uint8_t *in= &input[0];
   uint8_t orig[1000000];
   uint8_t *original = &orig[0];
   uint8_t output[100000];
   uint8_t *ou = &output[0];
   string line;

   string text_file = file_name + ".txt" ;
   string encrypt_file_name=file_name + "_encrypt.dat";
   string decrypt_file_name=file_name + "_decrypt.dat";
   ifstream myfile (text_file);
      

   if (myfile.is_open())
    {
     while ( getline (myfile,line) )
     	
     for (unsigned i=0; i<line.length(); ++i)
     {
       *(in+count)=(unsigned char)line.at(i);
       count=count + 1;
        
     }
     myfile.close();
    }

    else cout << "Unable to open file"; 

   
    for (unsigned i=0; i<count; ++i)
     {
   	 *(original+i)= *(in+i);
         
    } 
   
   

   
    encrypt_ecb(in);
      
    for (unsigned i=0; i<count; ++i)
    {
   	 write_to_binary_file(encrypt_file_name, *(in+i));
    } 
    
    decrypt_ecb(in);
    
    for (unsigned i=0; i<count; ++i)
    {    
   	 write_to_binary_file(decrypt_file_name, *(in+i));
    } 

   if (0 == memcmp((char*) in, (char*) original, count)) {
        printf("SUCCESS!\n");
	return(0);
    } else {
        printf("FAILURE!\n");
	return(1);
    }
}


void RelaxaseClient::encrypt_ecb(uint8_t *in)
{ 
  struct AES_ctx ctx;
  AES_init_ctx(&ctx, key);
  AES_ECB_encrypt(&ctx, in);
  
}


void RelaxaseClient::decrypt_ecb(uint8_t *in)
{
 
 struct AES_ctx ctx;
 
 AES_init_ctx(&ctx, key);
 AES_ECB_decrypt(&ctx, in);

for (unsigned i=0; i<count; ++i)
    {    cout<< *(in+i);
}
}


void RelaxaseClient:: write_to_binary_file(string fname,uint8_t p_Data)
{
	fstream binary_file(fname,ios::out|ios::binary|ios::app);
	binary_file.write(reinterpret_cast<char *>(&p_Data),sizeof(uint8_t));
	binary_file.close();
}



