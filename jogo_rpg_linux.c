#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define tamanho 50
int main(){
  setlocale(LC_ALL, "Portuguese_Brazil");
  int sair=0;
  do{
  srand(time(NULL));
  //Especificações do barbaro
  int vida_barbaro=220,ataque_corpo_barbaro=21,ataque_longe_barbaro=15,cura_barbaro=15;

  //Especificações do Arqueiro
  int vida_arqueiro=200,ataque_corpo_arqueiro=18,ataque_longe_arqueiro=22,cura_arqueiro=17;
  //Especificações do mago
  int vida_mago=180,ataque_corpo_mago=16,ataque_longe_mago=18,cura_mago=20;
  //Especificações do chefão
  int vida_chefao=250,ataque_corpo_chefao=25,ataque_longe_chefao=13,cura_chefao=13;
  int contador_vida=0,maximo=3;
  int personagem,golpe_personagem=1,golpe;
  int golpe_chefao,contador_chefao=1;
  ///////////////////////////////////////////////////////////
  char nome[tamanho];
	//layout do jogo:
	printf("><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n");
	printf("     <::::::{==O SEJA BEM VINDO AO JOGO DE RPG. O==}::::::>\n");
	printf("><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n\n");
	printf("->Escolha a sua classe para batalhar com o grande chefão Crawmerax:\n\n");
	printf(" 1= Bárbaro(a)\n          >Atributos<\n -Ataque Corpo a Corpo: 21(±3)\n -Ataque à Distância: 15(±2)\n -Cura: 15(±3)\n -Vida: 220\n\n");
  	printf(" 2= Arqueiro(a)\n          >Atributos<\n -Ataque Corpo a Corpo: 18(±2)\n -Ataque à Distância: 22(±6)\n -Cura: 17(±3)\n -Vida: 200\n\n");
	printf(" 3= Mago(a)\n          >Atributos<\n -Ataque Corpo a Corpo: 16(±2)\n -Ataque à Distância: 18(±4)\n -Cura: 20(±2)\n -Vida: 180\n\n");
	printf("==============================================================\n");
	printf("                    --> Chefão Crawmerax <--\n\n");
	printf("                           >Atributos<\n");
	printf("                   -Ataque Corpo a Corpo: 25(±3)\n");
	printf("                   -Ataque à Distância: 13(±3)\n");
	printf("                   -Cura: 13(±2)\n");
	printf("                   -Vida: 250\n");
	printf("==============================================================\n");
    printf("Digite aqui a escolha da sua classe(1,2,3):");
	scanf("%d",&personagem);
    printf("==============================================================\n");
	switch(personagem){
		//Primeiro personagem(barbaro)
    case 1:
			printf("\e[H\e[2J");
      printf("==============================================================\n");
			printf("Você escolheu a classe Bárbaro(a).\n");
			printf("==============================================================\n");
			printf("Qual será o nick do seu personagem? Digite sem espaços:"); scanf("%s",nome);
			printf("==============================================================\n");
			printf("\e[H\e[2J");
      printf("Jogo carregado com sucesso...\nO nome do personagem escolhido foi: %s \nPronto para o combate.\n",nome);
			printf("==============================================================\n");
			printf("Que a sorte esteja ao seu lado :)\n");
			printf("==============================================================\n");
      printf("O primeiro a jogar será você, e ficará alternando de rodada em\nrodada entre você e o chefão.\n");
      //Atributos do barbaro.
      while(vida_barbaro>0 && vida_chefao>0){
        printf("==============================================================\n");
        printf("- Classe: Barbaro\n\n");
        printf("%dº golpe do:%s\n",golpe_personagem,nome);
        golpe_personagem++;
        printf("Escolha que golpe você deseja efetuar:\n 1)Ataque Corpo a Corpo: 21(±3)\n 2)Ataque à Distância: 15(±2)\n 3)Cura: 15(±3)\n");
        printf("Digite aqui o número do golpe:");
        scanf("%d",&golpe);
        printf("\e[H\e[2J");
        //Golpes do barbaro
        switch(golpe){

          //Golpe corpo a corpo(barbaro)
          case 1:
            ataque_corpo_barbaro=21;
            if(vida_barbaro<88){
              ataque_corpo_barbaro=21+8.4;
              printf("Especial 40 critico do barbaro ativado(Corpo a Corpo)\n");

            }
            if(vida_barbaro<44){
              ataque_corpo_barbaro=21+14.7;
              printf("Especial 70 critico do barbaro ativado(Corpo a Corpo)\n");
            }
            ataque_corpo_barbaro=ataque_corpo_barbaro + (rand()%4) - (rand()%4);
            if(vida_chefao<38){
                printf("@@Especial(carapuça, reduz seus danos) do chefão crawmerax ativada cuidado!!\n");
                ataque_corpo_barbaro=21-(rand()&7);
            }
            printf("==============================================================\n");
            printf(">Golpe escolhido: Corpo a Corpo<\n-Tirou %d da vida do chefão-\n",ataque_corpo_barbaro);
            vida_chefao=vida_chefao-ataque_corpo_barbaro;
            if(vida_barbaro<0){
                vida_barbaro=0;
            }
            if(vida_chefao<0){
                vida_chefao=0;
            }
            printf("Sua vida está:%d\n",vida_barbaro);
            printf("A vida do chefão está:%d\n",vida_chefao);
            printf("==============================================================\n");
            printf("Agora é a vez do chefão -\n");
            printf("%dº golpe do chefão...\n",contador_chefao);
            printf("==============================================================\n");
            contador_chefao++;
            int golpe_a=ataque_corpo_chefao + (rand()%4)-(rand()%4);
                int golpe_b=ataque_longe_chefao + (rand()%4)-(rand()%4);
            int cura_a=cura_chefao + (rand()%3)-(rand()%3);
            golpe_chefao = 1+rand()%3;
            if(vida_barbaro>0 && vida_chefao>0){
              if(golpe_chefao==1){
                printf("Eu escolho o golpe: Corpo a Corpo :D\n");
                printf("Tirei %d da sua vida, hahahaha\n",golpe_a);
                vida_barbaro=vida_barbaro-golpe_a;
                if(vida_barbaro<0){
                    vida_barbaro=0;
                }
                if(vida_chefao<0){
                    vida_chefao=0;
                }
                printf("Sua vida agora está:%d\n",vida_barbaro);
                printf("Minha vida está:%d\n",vida_chefao);
              }
              if(golpe_chefao==2){
                printf("Eu escolho o golpe: Ataque à distância :D\n");
                vida_barbaro=vida_barbaro-golpe_b;
                if(vida_barbaro<0){
                    vida_barbaro=0;
                }
                if(vida_chefao<0){
                    vida_chefao=0;
                }
                printf("Tirei %d da sua vida, otário(a).\n",golpe_b);
                printf("Sua vida agora está:%d\n",vida_barbaro);
                printf("Minha vida está:%d\n",vida_chefao);
              }
              if(golpe_chefao==3){
                if(vida_chefao>75){
                    printf("Eu escolho usar a cura, vou aumentar minha vida seu babaca, vou acrescentar %d\n",cura_a);
                    vida_chefao=vida_chefao+cura_a;
                    if(vida_barbaro<0){
                        vida_barbaro=0;
                    }
                    if(vida_chefao<0){
                        vida_chefao=0;
                    }
                    printf("Minha vida agora aumentou para:%d hahaha, você consegue fazer isso?\n",vida_chefao);
                    printf("Minha vida está:%d\n",vida_chefao);
                    printf("Sua vida agora está:%d\n",vida_barbaro);
                }
                else{
                    printf("++++++Estou usando meu especial, seu otário, quando minha vida fica abaixo de 75, consigo conjurar minha cura ate 50\n");
                    vida_chefao=vida_chefao+13+(rand()%8);
                    if(vida_barbaro<0){
                        vida_barbaro=0;
                    }
                    if(vida_chefao<0){
                        vida_chefao=0;
                    }
                    printf("Minha vida agora aumentou para:%d hahaha, você consegue fazer isso?\n",vida_chefao);
                    printf("Minha vida está:%d\n",vida_chefao);
                    printf("Sua vida agora está:%d\n",vida_barbaro);
                }
             }
            }
            break;
          //Golpe a distância(barbaro)
          case 2:
            ataque_longe_barbaro=15;
            if(vida_barbaro<88){
              ataque_longe_barbaro=15+6;
              printf("Especial 40 critico do barbaro ativado(Ataque à distância)\n");

            }
            if(vida_barbaro<44){
              ataque_longe_barbaro=15+10.5;
              printf("Especial 70 critico do barbaro ativado(Ataque à distância)\n");
            }
            ataque_longe_barbaro=ataque_longe_barbaro+ (rand()%3)-(rand()%3);
            if(vida_chefao<38){
                printf("@@Especial(carapuça, reduz seus danos) do chefão crawmerax ativada cuidado!!\n");
                ataque_longe_barbaro=15-(rand()&6);
            }
            printf("==============================================================\n");
            printf(">Golpe escolhido: Ataque à distância<\n-Tirou %d da vida do chefão-\n",ataque_longe_barbaro);
            vida_chefao=vida_chefao-ataque_longe_barbaro;
            if(vida_barbaro<0){
                vida_barbaro=0;
            }
            if(vida_chefao<0){
                vida_chefao=0;
            }
            printf("Sua vida está:%d\n",vida_barbaro);
            printf("A vida do chefão está:%d\n",vida_chefao);
            printf("==============================================================\n");
            printf("Agora é a vez do chefão -\n");
            printf("%dº golpe do chefão...\n",contador_chefao);
            printf("==============================================================\n");
            contador_chefao++;
            int golpe_a2 = ataque_corpo_chefao + (rand()%4)-(rand()%4);
	          int golpe_b2 = ataque_longe_chefao + (rand()%4)-(rand()%4);
            int cura_a2 = cura_chefao + (rand()%3)-(rand()%3);
            golpe_chefao = 1+rand()%3;
            if(vida_barbaro>0 && vida_chefao>0){
              if(golpe_chefao==1){
                printf("Eu escolho o golpe: Corpo a Corpo :D\n");
                printf("Tirei %d da sua vida, hahahaha\n",golpe_a2);
                vida_barbaro=vida_barbaro-golpe_a2;
                if(vida_barbaro<0){
                    vida_barbaro=0;
                }
                if(vida_chefao<0){
                    vida_chefao=0;
                }
                printf("Sua vida agora está:%d\n",vida_barbaro);
                printf("Minha vida está:%d\n",vida_chefao);
              }
              if(golpe_chefao==2){
                printf("Eu escolho o golpe: Ataque à distância :D\n");
                vida_barbaro=vida_barbaro-golpe_b2;
                if(vida_barbaro<0){
                    vida_barbaro=0;
                }
                if(vida_chefao<0){
                    vida_chefao=0;
                }
                printf("Tirei %d da sua vida, otário(a).\n",golpe_b2);
                printf("Sua vida agora está:%d\n",vida_barbaro);
                printf("Minha vida está:%d\n",vida_chefao);
              }
              if(golpe_chefao==3){
                if(vida_chefao>75){
                    printf("Eu escolho usar a cura, vou aumentar minha vida seu babaca, vou acrescentar %d\n",cura_a);
                    vida_chefao=vida_chefao+cura_a;
                    if(vida_barbaro<0){
                        vida_barbaro=0;
                    }
                    if(vida_chefao<0){
                        vida_chefao=0;
                    }
                    printf("Minha vida agora aumentou para:%d hahaha, você consegue fazer isso?\n",vida_chefao);
                    printf("Minha vida está:%d\n",vida_chefao);
                    printf("Sua vida agora está:%d\n",vida_barbaro);
                }
                else{
                    printf("++++++Estou usando meu especial, seu otário, quando minha vida fica abaixo de 75, consigo conjurar minha cura ate 50\n");
                    vida_chefao=vida_chefao+13+(rand()%8);
                    if(vida_barbaro<0){
                        vida_barbaro=0;
                    }
                    if(vida_chefao<0){
                        vida_chefao=0;
                    }
                    printf("Minha vida agora aumentou para:%d hahaha, você consegue fazer isso?\n",vida_chefao);
                    printf("Minha vida está:%d\n",vida_chefao);
                    printf("Sua vida agora está:%d\n",vida_barbaro);
                }
             }
            }
            break;
          //Cura(barbaro)
          case 3:

            if(contador_vida!=maximo){
              cura_barbaro=15;
              if(vida_barbaro<88){
                cura_barbaro=15+6;
                printf("Especial 40 critico do barbaro ativado(Cura)\n");

              }
              if(vida_barbaro<44){
                cura_barbaro=15+10.5;
                printf("Especial 70 critico do barbaro ativado(cura)\n");
              }
              contador_vida=contador_vida + 1;
              cura_barbaro=cura_barbaro + (rand()%4)-(rand()%4);
              printf("==============================================================\n");
              printf(">Você escolheu se curar<\n-você conseguiu acrescentar %d da sua vida-\n",cura_barbaro);
              vida_barbaro=vida_barbaro+cura_barbaro;
              if(vida_barbaro<0){
                vida_barbaro=0;
              }
              if(vida_chefao<0){
                vida_chefao=0;
              }
              printf("Sua vida está:%d\n",vida_barbaro);
              printf("A vida do chefão está:%d\n",vida_chefao);
              printf("==============================================================\n");
              printf("Agora é a vez do chefão -\n");
              printf("%dº golpe do chefão...\n",contador_chefao);
              printf("==============================================================\n");
              contador_chefao++;
              int golpe_a3 = ataque_corpo_chefao + (rand()%4)-(rand()%4);
              int golpe_b3 = ataque_longe_chefao + (rand()%4)-(rand()%4);
              int cura_a3 = cura_chefao + (rand()%3)-(rand()%3);
              golpe_chefao = 1+rand()%3;
              if(vida_barbaro>0 && vida_chefao>0){
                if(golpe_chefao==1){
                  printf("Eu escolho o golpe: Corpo a Corpo :D\n");
                  printf("Tirei %d da sua vida, hahahaha\n",golpe_a3);
                  vida_barbaro=vida_barbaro-golpe_a3;
                  if(vida_barbaro<0){
                    vida_barbaro=0;
                  }
                  if(vida_chefao<0){
                    vida_chefao=0;
                  }
                  printf("Sua vida agora está:%d\n",vida_barbaro);
                  printf("Minha vida está:%d\n",vida_chefao);
                }
                if(golpe_chefao==2){
                  printf("Eu escolho o golpe: Ataque à distância :D\n");
                  vida_barbaro=vida_barbaro-golpe_b3;
                  if(vida_barbaro<0){
                    vida_barbaro=0;
                  }
                  if(vida_chefao<0){
                    vida_chefao=0;
                  }
                  printf("Tirei %d da sua vida, otário(a).\n",golpe_b3);
                  printf("Sua vida agora está:%d\n",vida_barbaro);
                  printf("Minha vida está:%d\n",vida_chefao);
                }
                if(golpe_chefao==3){
                    if(vida_chefao>75){
                        printf("Eu escolho usar a cura, vou aumentar minha vida seu babaca, vou acrescentar %d\n",cura_a);
                        vida_chefao=vida_chefao+cura_a;
                        if(vida_barbaro<0){
                            vida_barbaro=0;
                        }
                        if(vida_chefao<0){
                            vida_chefao=0;
                        }
                        printf("Minha vida agora aumentou para:%d hahaha, você consegue fazer isso?\n",vida_chefao);
                        printf("Minha vida está:%d\n",vida_chefao);
                        printf("Sua vida agora está:%d\n",vida_barbaro);
                    }
                    else{
                        printf("++++++Estou usando meu especial, seu otário, quando minha vida fica abaixo de 75, consigo conjurar minha cura ate 50\n");
                        vida_chefao=vida_chefao+13+(rand()%8);
                        if(vida_barbaro<0){
                            vida_barbaro=0;
                        }
                        if(vida_chefao<0){
                            vida_chefao=0;
                        }
                        printf("Minha vida agora aumentou para:%d hahaha, você consegue fazer isso?\n",vida_chefao);
                        printf("Minha vida está:%d\n",vida_chefao);
                        printf("Sua vida agora está:%d\n",vida_barbaro);
                    }
             }
            }
              break;
            }
            else{
              printf("Você não pode usar mais a cura!!!!\n");
              break;
            }
            break;
          default:
            printf("opção invalida!\n");
        }
      }
      break;
    //Segundo personagem(Arqueiro)
    case 2:
			printf("\e[H\e[2J");
      printf("==============================================================\n");
			printf("Você escolheu a classe Arqueiro(a).\n");
			printf("==============================================================\n");
			printf("Qual será o nick do seu personagem? Digite sem espaços:"); scanf("%s",nome);
			printf("==============================================================\n");
			printf("\e[H\e[2J");
      printf("Jogo carregado com sucesso...\nO nome do personagem escolhido foi: %s \nPronto para o combate.\n",nome);
			printf("==============================================================\n");
			printf("Que a sorte esteja ao seu lado :)\n");
			printf("==============================================================\n");
      printf("O primeiro a jogar será você, e ficará alternando de rodada em\nrodada entre você e o chefão.\n");
      //Atributos do Arqueiro.
      while(vida_arqueiro>0 && vida_chefao>0){
        printf("==============================================================\n");
        printf("- Classe: Arqueiro\n\n");
        printf("%dº golpe do(a):%s\n",golpe_personagem,nome);
        golpe_personagem++;
        printf("Escolha que golpe você deseja efetuar:\n 1)Ataque Corpo a Corpo: 18(±2)\n 2)Ataque à Distância: 22(±6)\n 3)Cura: 17(±3)\n");
        printf("Digite aqui o número do golpe:");
        scanf("%d",&golpe);
        printf("\e[H\e[2J");
        //Golpes do Arqueiro
        switch(golpe){
          //Golpe Corpo a corpo(arqueiro)
          case 1:
            ataque_corpo_arqueiro=18;
            if(vida_arqueiro<80){
                ataque_corpo_arqueiro=18+9;
                printf("Especial 50 critico arqueiro ativado(corpo a corpo)\n");
            }
            if(vida_arqueiro<60){
                ataque_corpo_arqueiro=18+10.8;
                printf("Especial 60 critico arqueiro ativado(corpo a corpo)\n");
            }
            ataque_corpo_arqueiro=ataque_corpo_arqueiro + (rand()%3)-(rand()%3);
            if(vida_chefao<38){
                printf("@@Especial(carapuça, reduz seus danos) do chefão crawmerax ativada cuidado!!\n");
                ataque_corpo_arqueiro=18-(rand()&7);
            }
            printf("==============================================================\n");
            printf(">Golpe escolhido: Corpo a Corpo<\n-Tirou %d da vida do chefão-\n",ataque_corpo_arqueiro);
            vida_chefao=vida_chefao-ataque_corpo_arqueiro;
            if(vida_arqueiro<0){
                vida_arqueiro=0;
            }
            if(vida_chefao<0){
                vida_chefao=0;
            }
            printf("Sua vida está:%d\n",vida_arqueiro);
            printf("A vida do chefão está:%d\n",vida_chefao);
            printf("==============================================================\n");
            printf("Agora é a vez do chefão -\n");
            printf("%dº golpe do chefão...\n",contador_chefao);
            printf("==============================================================\n");
            contador_chefao++;
            int golpe_a=ataque_corpo_chefao + (rand()%4)-(rand()%4);
	          int golpe_b=ataque_longe_chefao + (rand()%4)-(rand()%4);
            int cura_a=cura_chefao + (rand()%3)-(rand()%3);
            golpe_chefao = 1+rand()%3;
            if(vida_arqueiro>0 && vida_chefao>0){
              if(golpe_chefao==1){
                printf("Eu escolho o golpe: Corpo a Corpo :D\n");
                printf("Tirei %d da sua vida, hahahaha\n",golpe_a);
                vida_arqueiro=vida_arqueiro-golpe_a;
                if(vida_arqueiro<0){
                    vida_arqueiro=0;
                }
                if(vida_chefao<0){
                    vida_chefao=0;
                }
                printf("Sua vida agora está:%d\n",vida_arqueiro);
                printf("Minha vida está:%d\n",vida_chefao);
              }
              if(golpe_chefao==2){
                printf("Eu escolho o golpe: Ataque à distância :D\n");
                vida_arqueiro=vida_arqueiro-golpe_b;
                if(vida_arqueiro<0){
                    vida_arqueiro=0;
                }
                if(vida_chefao<0){
                    vida_chefao=0;
                }
                printf("Tirei %d da sua vida, otário(a).\n",golpe_b);
                printf("Sua vida agora está:%d\n",vida_arqueiro);
                printf("Minha vida está:%d\n",vida_chefao);
              }
              if(golpe_chefao==3){
                if(vida_chefao>75){
                    printf("Eu escolho usar a cura, vou aumentar minha vida seu babaca, vou acrescentar %d\n",cura_a);
                    vida_chefao=vida_chefao+cura_a;
                    if(vida_arqueiro<0){
                        vida_arqueiro=0;
                    }
                    if(vida_chefao<0){
                        vida_chefao=0;
                    }
                    printf("Minha vida agora aumentou para:%d hahaha, você consegue fazer isso?\n",vida_chefao);
                    printf("Minha vida está:%d\n",vida_chefao);
                    printf("Sua vida agora está:%d\n",vida_arqueiro);
                }
                else{
                    printf("++++++Estou usando meu especial, seu otário, quando minha vida fica abaixo de 75, consigo conjurar minha cura ate 50\n");
                    vida_chefao=vida_chefao+13+(rand()%8);
                    if(vida_arqueiro<0){
                        vida_arqueiro=0;
                    }
                    if(vida_chefao<0){
                        vida_chefao=0;
                    }
                    printf("Minha vida agora aumentou para:%d hahaha, você consegue fazer isso?\n",vida_chefao);
                    printf("Minha vida está:%d\n",vida_chefao);
                    printf("Sua vida agora está:%d\n",vida_arqueiro);
                }
             }
            }
            break;
          //Golpe a distância(Arqueiro)
          case 2:
            ataque_longe_arqueiro=22;
            if(vida_arqueiro<80){
                ataque_longe_arqueiro=22+11;
                printf("Especial 50 critico arqueiro ativado(ataque à distância)\n");
            }
            if(vida_arqueiro<60){
                ataque_longe_arqueiro=22+13.2;
                printf("Especial 60 critico arqueiro ativado(ataque à distância)\n");
            }
            ataque_longe_arqueiro=ataque_longe_arqueiro + (rand()%7)-(rand()%7);
            if(vida_chefao<38){
                printf("@@Especial(carapuça, reduz seus danos) do chefão crawmerax ativada cuidado!!\n");
                ataque_longe_arqueiro=22-(rand()&8);
            }
            printf("==============================================================\n");
            printf(">Golpe escolhido: Ataque à distância<\n-Tirou %d da vida do chefão-\n",ataque_longe_arqueiro);
            vida_chefao=vida_chefao-ataque_longe_arqueiro;
            if(vida_arqueiro<0){
                vida_arqueiro=0;
            }
            if(vida_chefao<0){
                vida_chefao=0;
            }
            printf("Sua vida está:%d\n",vida_arqueiro);
            printf("A vida do chefão está:%d\n",vida_chefao);
            printf("==============================================================\n");
            printf("Agora é a vez do chefão -\n");
            printf("%dº golpe do chefão...\n",contador_chefao);
            printf("==============================================================\n");
            contador_chefao++;
            int golpe_a2 = ataque_corpo_chefao + (rand()%4)-(rand()%4);
	          int golpe_b2 = ataque_longe_chefao + (rand()%4)-(rand()%4);
            int cura_a2 = cura_chefao + (rand()%3)-(rand()%3);
            golpe_chefao = 1+rand()%3;
            if(vida_arqueiro>0 && vida_chefao>0){
              if(golpe_chefao==1){
                printf("Eu escolho o golpe: Corpo a Corpo :D\n");
                printf("Tirei %d da sua vida, hahahaha\n",golpe_a2);
                vida_arqueiro=vida_arqueiro-golpe_a2;
                if(vida_arqueiro<0){
                    vida_arqueiro=0;
                }
                if(vida_chefao<0){
                    vida_chefao=0;
                }
                printf("Sua vida agora está:%d\n",vida_arqueiro);
                printf("Minha vida está:%d\n",vida_chefao);
              }
              if(golpe_chefao==2){
                printf("Eu escolho o golpe: Ataque à distância :D\n");
                vida_arqueiro=vida_arqueiro-golpe_b2;
                if(vida_arqueiro<0){
                    vida_arqueiro=0;
                }
                if(vida_chefao<0){
                    vida_chefao=0;
                }
                printf("Tirei %d da sua vida, otário(a).\n",golpe_b2);
                printf("Sua vida agora está:%d\n",vida_arqueiro);
                printf("Minha vida está:%d\n",vida_chefao);
              }
              if(golpe_chefao==3){
                if(vida_chefao>75){
                    printf("Eu escolho usar a cura, vou aumentar minha vida seu babaca, vou acrescentar %d\n",cura_a);
                    vida_chefao=vida_chefao+cura_a;
                    if(vida_arqueiro<0){
                        vida_arqueiro=0;
                    }
                    if(vida_chefao<0){
                        vida_chefao=0;
                    }
                    printf("Minha vida agora aumentou para:%d hahaha, você consegue fazer isso?\n",vida_chefao);
                    printf("Minha vida está:%d\n",vida_chefao);
                    printf("Sua vida agora está:%d\n",vida_arqueiro);
                }
                else{
                    printf("++++++Estou usando meu especial, seu otário, quando minha vida fica abaixo de 75, consigo conjurar minha cura ate 50\n");
                    vida_chefao=vida_chefao+13+(rand()%8);
                    if(vida_arqueiro<0){
                        vida_arqueiro=0;
                    }
                    if(vida_chefao<0){
                        vida_chefao=0;
                    }
                    printf("Minha vida agora aumentou para:%d hahaha, você consegue fazer isso?\n",vida_chefao);
                    printf("Minha vida está:%d\n",vida_chefao);
                    printf("Sua vida agora está:%d\n",vida_arqueiro);
                }
             }
            }
            break;
          //Cura(Arqueiro)
          case 3:
            if(contador_vida!=maximo){
              cura_arqueiro=17;
              if(vida_arqueiro<80){
                cura_arqueiro=17+8.5;
                printf("Especial arqueiro ativado(cura)\n");
            }
            if(vida_arqueiro<60){
                ataque_corpo_arqueiro=17+10.2;
                printf("Especial arqueiro ativado(cura)\n");
            }
              contador_vida++;
              cura_arqueiro=cura_arqueiro + (rand()%4)-(rand()%4);
              printf("==============================================================\n");
              printf(">Você escolheu se curar<\n-você conseguiu acrescentar %d da sua vida-\n",cura_arqueiro);
              vida_arqueiro=vida_arqueiro+cura_arqueiro;
              if(vida_arqueiro<0){
                vida_arqueiro=0;
              }
              if(vida_chefao<0){
                vida_chefao=0;
              }
              printf("Sua vida está:%d\n",vida_arqueiro);
              printf("A vida do chefão está:%d\n",vida_chefao);
              printf("==============================================================\n");
              printf("Agora é a vez do chefão -\n");
              printf("%dº golpe do chefão...\n",contador_chefao);
              printf("==============================================================\n");
              contador_chefao++;
              int golpe_a3 = ataque_corpo_chefao + (rand()%4)-(rand()%4);
              int golpe_b3 = ataque_longe_chefao + (rand()%4)-(rand()%4);
              int cura_a3 = cura_chefao + (rand()%3)-(rand()%3);
              golpe_chefao = 1+rand()%3;
              if(vida_arqueiro>0 && vida_chefao>0){
                if(golpe_chefao==1){
                  printf("Eu escolho o golpe: Corpo a Corpo :D\n");
                  printf("Tirei %d da sua vida, hahahaha\n",golpe_a3);
                  vida_arqueiro=vida_arqueiro-golpe_a3;
                  if(vida_arqueiro<0){
                    vida_arqueiro=0;
                  }
                  if(vida_chefao<0){
                    vida_chefao=0;
                  }
                  printf("Sua vida agora está:%d\n",vida_arqueiro);
                  printf("Minha vida está:%d\n",vida_chefao);
                }
                if(golpe_chefao==2){
                  printf("Eu escolho o golpe: Ataque à distância :D\n");
                  vida_arqueiro=vida_arqueiro-golpe_b3;
                  if(vida_arqueiro<0){
                    vida_arqueiro=0;
                  }
                  if(vida_chefao<0){
                    vida_chefao=0;
                  }
                  printf("Tirei %d da sua vida, otário(a).\n",golpe_b3);
                  printf("Sua vida agora está:%d\n",vida_arqueiro);
                  printf("Minha vida está:%d\n",vida_chefao);
                }
                if(golpe_chefao==3){
                if(vida_chefao>75){
                    printf("Eu escolho usar a cura, vou aumentar minha vida seu babaca, vou acrescentar %d\n",cura_a);
                    vida_chefao=vida_chefao+cura_a;
                    if(vida_arqueiro<0){
                        vida_arqueiro=0;
                    }
                    if(vida_chefao<0){
                        vida_chefao=0;
                    }
                    printf("Minha vida agora aumentou para:%d hahaha, você consegue fazer isso?\n",vida_chefao);
                    printf("Minha vida está:%d\n",vida_chefao);
                    printf("Sua vida agora está:%d\n",vida_arqueiro);
                }
                else{
                    printf("++++++Estou usando meu especial, seu otário, quando minha vida fica abaixo de 75, consigo conjurar minha cura ate 50\n");
                    vida_chefao=vida_chefao+13+(rand()%8);
                    if(vida_arqueiro<0){
                        vida_arqueiro=0;
                    }
                    if(vida_chefao<0){
                        vida_chefao=0;
                    }
                    printf("Minha vida agora aumentou para:%d hahaha, você consegue fazer isso?\n",vida_chefao);
                    printf("Minha vida está:%d\n",vida_chefao);
                    printf("Sua vida agora está:%d\n",vida_arqueiro);
                }
             }
            }
              break;
            }
            else{
              printf("Você não pode usar mais a cura!!!!\n");
              break;
            }
            break;

          default:
            printf("opção invalida!\n");
        }
      }
      break;
    //Terceiro personagem(mago)
    case 3:
			printf("\e[H\e[2J");
      printf("==============================================================\n");
			printf("Você escolheu a classe Mago(a).\n");
			printf("==============================================================\n");
			printf("Qual será o nick do seu personagem? Digite sem espaços:"); scanf("%s",nome);
			printf("==============================================================\n");
			printf("\e[H\e[2J");
      printf("Jogo carregado com sucesso...\nO nome do personagem escolhido foi: %s \nPronto para o combate.\n",nome);
			printf("==============================================================\n");
			printf("Que a sorte esteja ao seu lado :)\n");
			printf("==============================================================\n");
      printf("O primeiro a jogar será você, e ficará alternando de rodada em\nrodada entre você e o chefão.\n");
      //Atributos do Mago.
      while(vida_mago>0 && vida_chefao>0){
        printf("==============================================================\n");
        printf("- Classe: Mago\n\n");
        printf("%dº golpe do(a):%s\n",golpe_personagem,nome);
        golpe_personagem++;
        printf("Escolha que golpe você deseja efetuar:\n 1)Ataque Corpo a Corpo: 16(±2)\n 2)Ataque à Distância: 18(±4)\n 3)Cura: 20(±2)\n");
        printf("Digite aqui o número do golpe:");
        scanf("%d",&golpe);
        printf("\e[H\e[2J");
        //Golpes do Mago
        switch(golpe){
          //Golpe Corpo a corpo(Mago)
          case 1:
            ataque_corpo_mago=16;
            ataque_corpo_mago=ataque_corpo_mago + (rand()%3)-(rand()%3);
            //especial mago, dano.
            if(vida_mago<90){
                ataque_corpo_mago=ataque_corpo_mago+2;
                printf("Especial do dano do mago ativado com sucesso!!\n");
            }
            if(vida_chefao<38){
                printf("@@Especial(carapuça, reduz seus danos) do chefão crawmerax ativada cuidado!!\n");
                ataque_corpo_mago=16-(rand()&6);
            }
            printf("==============================================================\n");
            printf(">Golpe escolhido: Corpo a Corpo<\n-Tirou %d da vida do chefão-\n",ataque_corpo_mago);
            vida_chefao=vida_chefao-ataque_corpo_mago;
            if(vida_mago<0){
                vida_mago=0;
            }
            if(vida_chefao<0){
                vida_chefao=0;
            }
            printf("Sua vida está:%d\n",vida_mago);
            printf("A vida do chefão está:%d\n",vida_chefao);
            printf("==============================================================\n");
            printf("Agora é a vez do chefão -\n");
            printf("%dº golpe do chefão...\n",contador_chefao);
            printf("==============================================================\n");
            contador_chefao++;
            int golpe_a=ataque_corpo_chefao + (rand()%4)-(rand()%4);
	          int golpe_b=ataque_longe_chefao + (rand()%4)-(rand()%4);
            int cura_a=cura_chefao + (rand()%3)-(rand()%3);
            golpe_chefao = 1+rand()%3;
            if(vida_mago>0 && vida_chefao>0){
              if(golpe_chefao==1){
                printf("Eu escolho o golpe: Corpo a Corpo :D\n");
                if(vida_mago<90){
                    golpe_a=golpe_a-(rand()%8);
                    printf("++++++Você está reduzindo os danos dos meus golpes com seu especial(quando sua vida fica abaixo de 90)\n");
                }
                if(vida_mago<54){
                    golpe_a=golpe_a-(rand()%8);
                    printf("++++++Você está reduzindo ainda mais os meus golpes com seu especial!!!(quando sua vida fica abaixo de 54)\n");
                }
                printf("Tirei %d da sua vida, hahahaha\n",golpe_a);
                vida_mago=vida_mago-golpe_a;
                if(vida_mago<0){
                    vida_mago=0;
                }
                if(vida_chefao<0){
                    vida_chefao=0;
                }
                printf("Sua vida agora está:%d\n",vida_mago);
                printf("Minha vida está:%d\n",vida_chefao);
              }
              if(golpe_chefao==2){
                printf("Eu escolho o golpe: Ataque à distância :D\n");
                if(vida_mago<90){
                    golpe_b=golpe_b-(rand()%8);
                    printf("++++++Você está reduzindo os danos dos meus golpes com seu especial(quando sua vida fica abaixo de 90)\n");
                }
                if(vida_mago<54){
                    golpe_b=golpe_b-(rand()%8);
                    printf("++++++Você está reduzindo ainda mais os meus golpes com seu especial!!!(quando sua vida fica abaixo de 54)\n");
                }
                vida_mago=vida_mago-golpe_b;
                if(vida_mago<0){
                    vida_mago=0;
                }
                if(vida_chefao<0){
                    vida_chefao=0;
                }
                printf("Tirei %d da sua vida, otário(a).\n",golpe_b);
                printf("Sua vida agora está:%d\n",vida_mago);
                printf("Minha vida está:%d\n",vida_chefao);
              }
              if(golpe_chefao==3){
                if(vida_chefao>75){
                    printf("Eu escolho usar a cura, vou aumentar minha vida seu babaca, vou acrescentar %d\n",cura_a);
                    vida_chefao=vida_chefao+cura_a;
                    if(vida_mago<0){
                        vida_mago=0;
                    }
                    if(vida_chefao<0){
                        vida_chefao=0;
                    }
                    printf("Minha vida agora aumentou para:%d hahaha, você consegue fazer isso?\n",vida_chefao);
                    printf("Minha vida está:%d\n",vida_chefao);
                    printf("Sua vida agora está:%d\n",vida_mago);
                }
                else{
                    printf("++++++Estou usando meu especial, seu otário, quando minha vida fica abaixo de 75, consigo conjurar minha cura ate 50\n");
                    vida_chefao=vida_chefao+13+(rand()%8);
                    if(vida_mago<0){
                        vida_mago=0;
                    }
                    if(vida_chefao<0){
                        vida_chefao=0;
                    }
                    printf("Minha vida agora aumentou para:%d hahaha, você consegue fazer isso?\n",vida_chefao);
                    printf("Minha vida está:%d\n",vida_chefao);
                    printf("Sua vida agora está:%d\n",vida_mago);
                }
             }
            }
            break;
          //Golpe a distância(Mago)
          case 2:
            ataque_longe_mago=18;
            ataque_longe_mago=ataque_longe_mago+ (rand()%5)-(rand()%5);
            if(vida_mago<90){
                ataque_longe_mago=ataque_longe_mago+4;
                printf("Especial do dano do mago ativado com sucesso!!\n");
            }
            if(vida_chefao<38){
                printf("@@Especial(carapuça, reduz seus danos) do chefão crawmerax ativada cuidado!!\n");
                ataque_longe_mago=18-(rand()&7);
            }
            printf("==============================================================\n");
            printf(">Golpe escolhido: Ataque à distância<\n-Tirou %d da vida do chefão-\n",ataque_longe_mago);
            vida_chefao=vida_chefao-ataque_longe_mago;
            if(vida_mago<0){
                vida_mago=0;
            }
            if(vida_chefao<0){
                vida_chefao=0;
            }
            printf("Sua vida está:%d\n",vida_mago);
            printf("A vida do chefão está:%d\n",vida_chefao);
            printf("==============================================================\n");
            printf("Agora é a vez do chefão -\n");
            printf("%dº golpe do chefão...\n",contador_chefao);
            printf("==============================================================\n");
            contador_chefao++;
            int golpe_a2 = ataque_corpo_chefao + (rand()%4)-(rand()%4);
	          int golpe_b2 = ataque_longe_chefao + (rand()%4)-(rand()%4);
            int cura_a2 = cura_chefao + (rand()%3)-(rand()%3);
            golpe_chefao = 1+rand()%3;
            if(vida_mago>0 && vida_chefao>0){
              if(golpe_chefao==1){
                printf("Eu escolho o golpe: Corpo a Corpo :D\n");
                if(vida_mago<90){
                    golpe_a2=golpe_a2-(rand()%8);
                    printf("++++++Você está reduzindo os danos dos meus golpes com seu especial(quando sua vida fica abaixo de 90)\n");
                }
                if(vida_mago<54){
                    golpe_a2=golpe_a2-(rand()%8);
                    printf("++++++Você está reduzindo ainda mais os meus golpes com seu especial!!!(quando sua vida fica abaixo de 54)\n");
                }
                printf("Tirei %d da sua vida, hahahaha\n",golpe_a2);
                vida_mago=vida_mago-golpe_a2;
                if(vida_mago<0){
                    vida_mago=0;
                }
                if(vida_chefao<0){
                    vida_chefao=0;
                }
                printf("Sua vida agora está:%d\n",vida_mago);
                printf("Minha vida está:%d\n",vida_chefao);
              }
              if(golpe_chefao==2){
                printf("Eu escolho o golpe: Ataque à distância :D\n");
                if(vida_mago<90){
                    golpe_b2=golpe_b2-(rand()%8);
                    printf("++++++Você está reduzindo os danos dos meus golpes com seu especial(quando sua vida fica abaixo de 90)\n");
                }
                if(vida_mago<54){
                    golpe_b2=golpe_b2-(rand()%8);
                    printf("++++++Você está reduzindo ainda mais os meus golpes com seu especial!!!(quando sua vida fica abaixo de 54)\n");
                }
                vida_mago=vida_mago-golpe_b2;
                if(vida_mago<0){
                    vida_mago=0;
                }
                if(vida_chefao<0){
                    vida_chefao=0;
                }
                printf("Tirei %d da sua vida, otário(a).\n",golpe_b2);
                printf("Sua vida agora está:%d\n",vida_mago);
                printf("Minha vida está:%d\n",vida_chefao);
              }
              if(golpe_chefao==3){
                if(vida_chefao>75){
                    printf("Eu escolho usar a cura, vou aumentar minha vida seu babaca, vou acrescentar %d\n",cura_a);
                    vida_chefao=vida_chefao+cura_a;
                    if(vida_mago<0){
                        vida_mago=0;
                    }
                    if(vida_chefao<0){
                        vida_chefao=0;
                    }
                    printf("Minha vida agora aumentou para:%d hahaha, você consegue fazer isso?\n",vida_chefao);
                    printf("Minha vida está:%d\n",vida_chefao);
                    printf("Sua vida agora está:%d\n",vida_mago);
                }
                else{
                    printf("++++++Estou usando meu especial, seu otário, quando minha vida fica abaixo de 75, consigo conjurar minha cura ate 50\n");
                    vida_chefao=vida_chefao+13+(rand()%8);
                    if(vida_mago<0){
                        vida_mago=0;
                    }
                    if(vida_chefao<0){
                        vida_chefao=0;
                    }
                    printf("Minha vida agora aumentou para:%d hahaha, você consegue fazer isso?\n",vida_chefao);
                    printf("Minha vida está:%d\n",vida_chefao);
                    printf("Sua vida agora está:%d\n",vida_mago);
                }
             }
            }
            break;
          //Cura(Mago)
          case 3:
            if(contador_vida!=maximo){
              cura_mago=20;
              contador_vida++;
              cura_mago=cura_mago + (rand()%3)-(rand()%3);
              printf("==============================================================\n");
              printf(">Você escolheu se curar<\n-você conseguiu acrescentar %d da sua vida-\n",cura_mago);
              vida_mago=vida_mago+cura_mago;
              if(vida_mago<0){
                vida_mago=0;
              }
              if(vida_chefao<0){
                vida_chefao=0;
              }
              printf("Sua vida está:%d\n",vida_mago);
              printf("A vida do chefão está:%d\n",vida_chefao);
              printf("==============================================================\n");
              printf("Agora é a vez do chefão -\n");
              printf("%dº golpe do chefão...\n",contador_chefao);
              printf("==============================================================\n");
              contador_chefao++;
              int golpe_a3 = ataque_corpo_chefao + (rand()%4)-(rand()%4);
              int golpe_b3 = ataque_longe_chefao + (rand()%4)-(rand()%4);
              int cura_a3 = cura_chefao + (rand()%3)-(rand()%3);
              golpe_chefao = 1+rand()%3;
              if(vida_mago>0 && vida_chefao>0){
                if(golpe_chefao==1){
                  printf("Eu escolho o golpe: Corpo a Corpo :D\n");
                  if(vida_mago<90){
                    golpe_a3=golpe_a3-(rand()%8);
                    printf("++++++Você está reduzindo os danos dos meus golpes com seu especial(quando sua vida fica abaixo de 90)\n");
                }
                  if(vida_mago<54){
                    golpe_a3=golpe_a3-(rand()%8);
                    printf("++++++Você está reduzindo ainda mais os meus golpes com seu especial!!!(quando sua vida fica abaixo de 54)\n");
                }
                  printf("Tirei %d da sua vida, hahahaha\n",golpe_a3);
                  vida_mago=vida_mago-golpe_a3;
                  if(vida_mago<0){
                    vida_mago=0;
                  }
                  if(vida_chefao<0){
                    vida_chefao=0;
                  }
                  printf("Sua vida agora está:%d\n",vida_mago);
                  printf("Minha vida está:%d\n",vida_chefao);
                }
                if(golpe_chefao==2){
                  printf("Eu escolho o golpe: Ataque à distância :D\n");
                  if(vida_mago<90){
                    golpe_b3=golpe_b3-(rand()%8);
                    printf("++++++Você está reduzindo os danos dos meus golpes com seu especial(quando sua vida fica abaixo de 90)\n");
                    }
                  if(vida_mago<54){
                    golpe_b3=golpe_b3-(rand()%8);
                    printf("++++++Você está reduzindo ainda mais os meus golpes com seu especial!!!(quando sua vida fica abaixo de 54)\n");
                    }
                  vida_mago=vida_mago-golpe_b3;
                  if(vida_mago<0){
                    vida_mago=0;
                  }
                  if(vida_chefao<0){
                    vida_chefao=0;
                  }
                  printf("Tirei %d da sua vida, otário(a).\n",golpe_b3);
                  printf("Sua vida agora está:%d\n",vida_mago);
                  printf("Minha vida está:%d\n",vida_chefao);
                }
                if(golpe_chefao==3){
                if(vida_chefao>75){
                    printf("Eu escolho usar a cura, vou aumentar minha vida seu babaca, vou acrescentar %d\n",cura_a);
                    vida_chefao=vida_chefao+cura_a;
                    if(vida_mago<0){
                        vida_mago=0;
                    }
                    if(vida_chefao<0){
                        vida_chefao=0;
                    }
                    printf("Minha vida agora aumentou para:%d hahaha, você consegue fazer isso?\n",vida_chefao);
                    printf("Minha vida está:%d\n",vida_chefao);
                    printf("Sua vida agora está:%d\n",vida_mago);
                }
                else{
                    printf("++++++Estou usando meu especial, seu otário, quando minha vida fica abaixo de 75, consigo conjurar minha cura ate 50\n");
                    vida_chefao=vida_chefao+13+(rand()%8);
                    if(vida_mago<0){
                        vida_mago=0;
                    }
                    if(vida_chefao<0){
                        vida_chefao=0;
                    }
                    printf("Minha vida agora aumentou para:%d hahaha, você consegue fazer isso?\n",vida_chefao);
                    printf("Minha vida está:%d\n",vida_chefao);
                    printf("Sua vida agora está:%d\n",vida_mago);
                }
             }
            }
              break;
            }
            else{
              printf("Você não pode usar mais a cura!!!!\n");
              break;
            }
            break;
          default:
            printf("opção invalida!\n");
        }

      }
      break;
    default:
		  printf(" A escolha do personagem não coincide com os números das classes apresentados!\n");
  }
	//Se o chefão ganhar contra o barbaro
  if(personagem==1){
    if(vida_chefao>0 && vida_barbaro<=0){
      printf("+-+-+-+-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+\n");
      printf("Eu ganhei hahaha seu babaca\ntente novamente, se suas forças ainda derem conta de mim!\n");
      printf("+-+-+-+-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+\n");
    }
  }
  //Se o chefão ganhar contra o arqueiro
  if(personagem==2){
    if(vida_chefao>0 && vida_arqueiro<=0){
      printf("+-+-+-+-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+\n");
      printf("Eu ganhei hahaha seu babaca\ntenta de novamente, se for capaz!\n");
      printf("+-+-+-+-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+\n");
    }
  }
  //Se o chefão ganhar contra o mago
  if(personagem==3){
    if(vida_chefao>0 && vida_mago<=0){
      printf("+-+-+-+-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+\n");
      printf("Eu ganhei hahaha seu babaca\ntenta de novo, se for capaz, verme!\n");
      printf("+-+-+-+-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+\n");
    }
  }
  //Se o barbaro ganhar
  if(personagem==1){
    if(vida_barbaro>0 && vida_chefao<=0){
      printf("+-+-+-+-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+\n");
      printf("Parabéns %s, você e sua classe(Bábaro) ganharam.\n",nome);
      printf("+-+-+-+-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+\n");
    }
  }
  //Se o arqueiro ganhar
  if(personagem==2){
    if(vida_arqueiro>0 && vida_chefao<=0){
      printf("+-+-+-+-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+\n");
      printf("Parabéns %s, você e sua classe(arqueiro) ganharam.\n",nome);
      printf("+-+-+-+-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+\n");
    }
  }
  //Se o mago ganhar
  if(personagem==3){
    if(vida_mago>0 && vida_chefao<=0){
      printf("+-+-+-+-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+\n");
      printf("Parabéns %s, você e sua classe(mago) ganharam.\n",nome);
      printf("+-+-+-+-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+\n");
    }
  }

  printf(" você deseja jogar novamente?(Qualquer número=sim/1=não)\n responda aqui:");
  scanf("%d",&sair);
  printf("\e[H\e[2J");
  }while (sair!=1);

printf("FIM DE JOGO!");
}
