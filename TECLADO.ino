//importar biblioteca
#include <Arduino.h>


// declaraçao de variaveis que nao sao alteradas
/* Chaves */
#define chave_sol_1 52
#define chave_la 50
#define chave_si 48
#define chave_do 46
#define chave_re 44
#define chave_mi 42
#define chave_fa 40
#define chave_sol_2 38

/* LEDs */
#define led_sol_1 13 
#define led_la 12
#define led_si 11
#define led_do 10
#define led_re 9
#define led_mi 8
#define led_fa 7
#define led_sol_2 6

// prototipagem de funcao
void mudaLed();
void apertaChave();

//variavel global
char proximo = 1;
int valor = 28;


// funcao que e' execultada uma vez (quando liga ou reset o arduino)
void setup() {
   // Define todas as portas do 6 até a 13, como saidas
   for(short i=6;i<=13;i++) 
   pinMode(i, OUTPUT); 
   
   
   // Define todas as portas do 38 até a 52, como entrada
   for(short i=38;i<=52;i++) 
   pinMode(i, INPUT_PULLUP); 
     

}

// funcao executada infinitamente, ate que o arduino seja desligado
void loop() {
    
     apertaChave(); //Função para apertar a chave
     mudaLed(); //Função para mudar o Led
   
   
}

//funcao aperta chave
void apertaChave()
{
 
   if(!digitalRead(chave_sol_1)|| !digitalRead(chave_la)
     || !digitalRead(chave_si) || !digitalRead(chave_do) 
     || !digitalRead(chave_re) || !digitalRead(chave_mi) 
     || !digitalRead(chave_fa) || !digitalRead(chave_sol_2)) { 
       delay(300); //delay para evitar que (1mils)
       //aperte e sai piscando tudo de uma vez 
       proximo++; //Incrementar o valor de "proximo"
      
       if(proximo > valor) 
         proximo = 1;
   }
 
 
}


