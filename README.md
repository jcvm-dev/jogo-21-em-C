# 🃏 Jogo de 21 em C

Um jogo de cartas simples, inspirado no **Blackjack (ou 21)**, desenvolvido em **linguagem C**.  
O objetivo é somar cartas até chegar o mais próximo possível de **21 pontos**, sem ultrapassar esse valor.

---

## 📘 Sobre o jogo

O **Jogo de 21** é disputado entre **dois jogadores**.  
Cada um recebe cartas aleatórias de um baralho virtual e decide se quer continuar comprando ou parar, tentando chegar o mais próximo possível de 21 pontos.

### 🎯 Regras básicas

- O jogo usa um baralho comum com **52 cartas** (sem coringas).  
- O **naipe das cartas não importa**, apenas o valor numérico.  
- As cartas possuem os seguintes valores:
  - **2 a 10:** valor igual ao número da carta  
  - **Valetes (J), Damas (Q) e Reis (K):** valem **10 pontos**
  - **Ás (A):** vale **1** ou **11** pontos, dependendo da soma atual das cartas do jogador  

---

## ⚙️ Como funciona

1. O programa exibe as **instruções** e solicita o **nome dos dois jogadores**.
2. O **Jogador 1** começa:
   - Recebe uma carta sorteada.
   - Pode escolher se quer **comprar outra carta (S)** ou **parar (N)**.
3. Depois, o **Jogador 2** repete o mesmo processo.
4. O programa exibe o **resultado final**, mostrando:
   - Pontuação de cada jogador;
   - Quem venceu;
   - Ou se houve empate.

---

## 💻 Tecnologias utilizadas

- **Linguagem:** C  
- **Bibliotecas padrão utilizadas:**
  - `stdio.h`
  - `stdlib.h`
  - `conio.h`
  - `time.h`
  - `ctype.h`
  - `locale.h`

---

## 🚀 Como executar o projeto

1. **Clone o repositório:**

    ```bash
    git clone https://github.com/SEU_USUARIO/jogo-de-21-c.git
    cd jogo-de-21-c


    ```bash
    gcc jogo21.c -o jogo21.exe7 

    ```bash
    jogo21.exe