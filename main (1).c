
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void decimalToBinary(int num, char *output, int size) {
    if (num == 0) {
       // printf("0");
        return;
    }

   // Stores binary representation of number.
   int binaryNum[8]; // Assuming 32 bit integer.
   int i=0;

   for ( ;num > 0; ){
      binaryNum[i++] = num % 2;
      num /= 2;
   }
   size--;
   int j=0;
   while(j<i){
    output[size]=binaryNum[j++]+'0';
    size--;
   }
}
void convertAssemblytoBinary(char * opcode, char * values, char * bitoutput){

    if(!(strcmp(opcode, "SUB")) || !(strcmp(opcode, "ADD")) ||!(strcmp(opcode, "AND")) ||!(strcmp(opcode, "OR")) ||
       !(strcmp(opcode, "XOR")) || !(strcmp(opcode, "ADDI")) ||!(strcmp(opcode, "SUBI")) ||!(strcmp(opcode, "ANDI"))){ bitoutput[0] = '0';}
    else{bitoutput[0] = '1';}

    if(!(strcmp(opcode, "SUB")) || !(strcmp(opcode, "ADD")) ||!(strcmp(opcode, "AND")) ||!(strcmp(opcode, "OR")) ||
       !(strcmp(opcode, "ORI")) || !(strcmp(opcode, "XORI")) ||!(strcmp(opcode, "LD")) ||!(strcmp(opcode, "ST"))){ bitoutput[1] = '0';}
    else{bitoutput[1] = '1';}

    if(!(strcmp(opcode, "SUB")) || !(strcmp(opcode, "ADD")) ||!(strcmp(opcode, "XOR")) ||!(strcmp(opcode, "ADDI")) ||
       !(strcmp(opcode, "ORI")) || !(strcmp(opcode, "XORI")) ||!(strcmp(opcode, "JUMP")) ||!(strcmp(opcode, "PUSH"))){ bitoutput[2] = '0';}
    else{bitoutput[2] = '1';}

    if(!(strcmp(opcode, "SUB")) || !(strcmp(opcode, "AND")) ||!(strcmp(opcode, "XOR")) ||!(strcmp(opcode, "SUBI")) ||
       !(strcmp(opcode, "ORI")) || !(strcmp(opcode, "LD")) ||!(strcmp(opcode, "JUMP")) ||!(strcmp(opcode, "POP"))){ bitoutput[3] = '0';}
    else{bitoutput[3] = '1';}
       // Till This point get the first 4 bit
    int index=3;
    int vindex=0;
    int src=0;
    int i=0;
    int srci=0;
    int size;
    //char output[]="0000";
    if(!(strcmp(opcode, "SUB")) || !(strcmp(opcode, "ADD")) ||!(strcmp(opcode, "AND")) ||!(strcmp(opcode, "OR")) ||!(strcmp(opcode, "XOR") )) {

    while(vindex!=20){
       char output[]="0000";
       size= sizeof(output)/sizeof(output[0])-1;
        src=0;
        i=0;
        if(srci==2){
         for(i=0;i<4;i++){
         index++;
         bitoutput[index]='0';
}

        }

    if(values[vindex]=='R'){
        vindex++;
        //We got the Which Src are we dealing with
        while(values[vindex]!=','&& values[vindex]!='\0'){
        src= src*10 + values[vindex] -'0';
        vindex++;
        }
        srci++;
    decimalToBinary(src,output,size);
    for(i=0;i<4;i++){
    index++;
    bitoutput[index]=output[i];
}


    }
    vindex++;
    }
    }


   if(!(strcmp(opcode, "ADDI")) || !(strcmp(opcode, "SUBI")) ||!(strcmp(opcode, "ANDI")) ||!(strcmp(opcode, "ORI")) ||!(strcmp(opcode, "XORI") )){

        while(vindex!=20){
        char output[]="00000000";
        size=sizeof(output) / sizeof(output[0])-1;

        src=0;
        i=0;

    if(values[vindex]=='R'){
        vindex++;
        //We got the Which Src are we dealing with
        while(values[vindex]!=','&& values[vindex]!='\0'){
        src= src*10 + values[vindex] -'0';
        vindex++;
        }

    decimalToBinary(src,output,size);
    for(i=4;i<8;i++){
    index++;
    bitoutput[index]=output[i];
}


    }
     if(isdigit(values[vindex])==1){

        while(values[vindex]!=','&& values[vindex]!='\0'){
        src= src*10 + values[vindex] -'0';
        vindex++;
        }
       decimalToBinary(src,output,size);
       for(i=0;i<8;i++){
       index++;
       bitoutput[index]=output[i];
}

     }
    vindex++;
    }

   }


   if(!(strcmp(opcode, "LD")) || !(strcmp(opcode, "ST"))){


       while(vindex!=20){
       char output[]="000000000000";
       size= sizeof(output)/sizeof(output[0])-1;
        src=0;
        i=0;


    if(values[vindex]=='R'){
        vindex++;
        //We got the Which Src are we dealing with
        while(values[vindex]!=','&& values[vindex]!='\0'){
        src= src*10 + values[vindex] -'0';
        vindex++;
        }


    decimalToBinary(src,output,size);
    for(i=8;i<12;i++){
    index++;
    bitoutput[index]=output[i];
}
}
        if(isdigit(values[vindex])==1){   //Hata Var abc.txt de 6. Rakamý 1 7. rakamý 2 olarak alýyor. Çünkü önceden gelen degerleri tekrar silmiyoruz.
        while(values[vindex]!=','&& values[vindex]!='\0'){
        src= src*10 + values[vindex] -'0';
        vindex++;
        }
       decimalToBinary(src,output,size);
       for(i=0;i<12;i++){
       index++;
       bitoutput[index]=output[i];
}
     break;
     }
  vindex++;
    }
 }

   if(!(strcmp(opcode, "JUMP")) || !(strcmp(opcode, "PUSH")) || !(strcmp(opcode, "POP"))){
               while(vindex!=20){
       char output[]="0000000000000000";
       size= sizeof(output)/sizeof(output[0])-1;
        src=0;
        i=0;


    if(values[vindex]=='R'){
        vindex++;
        //We got the Which Src are we dealing with
        while(values[vindex]!=','&& values[vindex]!='\0'){
        src= src*10 + values[vindex] -'0';
        vindex++;
        }


    decimalToBinary(src,output,size);
    for(i=0;i<16;i++){
    index++;
    bitoutput[index]=output[i];
    }
}
break;
}


   }

   if(!(strcmp(opcode, "BE")) || !(strcmp(opcode, "BNE")) ){ //Need To Get Right Coding For Adress
    bitoutput[index++]='0';
    bitoutput[index++]='1';

        while(vindex!=20){
       char output[]="000000";
       size= sizeof(output)/sizeof(output[0])-1;
        src=0;
        i=0;




    if(values[vindex]=='$'){
        vindex++;
        //We got the Which Src are we dealing with
        while(values[vindex]!=','&& values[vindex]!='\0'){
        src= src*10 + values[vindex] -'0';
        vindex++;
        }

    decimalToBinary(src,output,size);
    for(i=2;i<6;i++){
    index++;
    bitoutput[index]=output[i];
}


    }
       if(isdigit(values[vindex])==1){
        while(values[vindex]!=','&& values[vindex]!='\0'){
        src= src*10 + values[vindex] -'0';
        vindex++;
        }
       decimalToBinary(src,output,size);
       for(i=0;i<8;i++){
       index++;
       bitoutput[index]=output[i];
}
     break;
     }
    vindex++;
    }
   }
}



void convertBinarytoHex(char * binoutput,  char * hexoutput){

    char *a = binoutput;
   int num = 0;
do {
    int b = *a=='1'?1:0;
    num = (num<<1)|b;
    a++;
} while (*a);
     printf("%X  ", num);
    //printf("%s  \n",binoutput);
}

int main() {
    FILE* file;

	char fileName[100];
    char instruction[100];
    int programCounter;
    char opcode[5];
    char values[20];
    int registers[15];
    char hexoutput[5];
    char bitoutput[20];

    printf("Please enter the name of the input file :\n");
	scanf("%s", fileName);
	//char fileNames="abc.txt";
	printf("\n");
	file = fopen(fileName, "r");

    while(!feof(file)){
        fscanf(file,"%s %s",opcode,values);
       //  printf("%s  %s \n",opcode,values);
        convertAssemblytoBinary(opcode, values, hexoutput);
        convertBinarytoHex(hexoutput, bitoutput);
    }

   return 0;
}
