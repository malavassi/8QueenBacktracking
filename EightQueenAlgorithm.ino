//Basado en los codigos obtenidos de:
//http://osoyoo.com/2017/07/arduino-lesson-8x8-led-matrix/#2.2
//https://www.dyclassroom.com/backtracking-algorithm/n-queen-problem
// 2-dimensional array of row pin numbers:
int R[] = {2,7,A5,5,13,A4,12,A2};  
// 2-dimensional array of column pin numbers:
int C[] = {6,11,10,3,A3,4,8,9};    
int contador = 0;
int todos[8][8] =       
{  
  1,1,1,1,1,1,1,1,  
  1,1,1,1,1,1,1,1,  
  1,1,1,1,1,1,1,1,  
  1,1,1,1,1,1,1,1,  
  1,1,1,1,1,1,1,1,  
  1,1,1,1,1,1,1,1,  
  1,1,1,1,1,1,1,1,  
  1,1,1,1,1,1,1,1,  
};  
  
int matriz[8][8] =       
{  
  0,0,0,0,0,0,0,0,  
  0,0,0,0,0,0,0,0,  
  0,0,0,0,0,0,0,0,  
  0,0,0,0,0,0,0,0,  
  0,0,0,0,0,0,0,0,  
  0,0,0,0,0,0,0,0,  
  0,0,0,0,0,0,0,0,  
  0,0,0,0,0,0,0,0,  
};  

int ayuda[8][8] =     
{  
  0,0,0,0,0,0,0,0,  
  0,0,0,0,0,0,0,0,  
  0,0,0,0,0,0,0,0,  
  0,0,0,0,0,0,0,0,  
  0,0,0,0,0,0,0,0,  
  0,0,0,0,0,0,0,0,  
  0,0,0,0,0,0,0,0,  
  0,0,0,0,0,0,0,0,  
}; 

int equis[8][8] =     
{  
  1,0,0,0,0,0,0,1,  
  0,1,0,0,0,0,1,0,  
  0,0,1,0,0,1,0,0,  
  0,0,0,1,0,0,0,0,  
  0,0,0,0,1,0,0,0,  
  0,0,1,0,0,1,0,0,  
  0,1,0,0,0,0,1,0,  
  1,0,0,0,0,0,0,1,  
}; 

int inicio[8][8] =    
{  
  0,0,0,0,0,0,0,0,  
  0,1,1,0,0,1,1,0,  
  0,1,1,0,0,1,1,0,  
  0,0,0,0,0,0,0,0,  
  0,1,0,0,0,0,1,0,  
  0,1,0,0,0,0,1,0,  
  0,1,1,1,1,1,1,0,  
  0,0,0,0,0,0,0,0,  
};  

int choque[8][8] =    
{  
  0,0,0,0,0,0,0,0,  
  0,1,1,0,0,1,1,0,  
  0,1,1,0,0,1,1,0,  
  0,0,0,0,0,0,0,0,  
  0,1,1,1,1,1,1,0,  
  0,1,0,0,0,0,1,0,  
  0,1,0,0,0,0,1,0,  
  0,0,0,0,0,0,0,0,  
}; 

int fin[8][8] =      
{  
  0,0,0,0,0,0,0,0,  
  1,1,1,0,1,1,1,0,  
  1,0,0,0,1,0,0,0,  
  1,0,0,0,1,1,1,0,  
  1,0,0,0,1,0,0,0,  
  1,0,1,0,1,1,1,0,  
  0,0,0,0,0,0,0,0,  
  0,0,0,0,0,0,0,0,  
};  
  
void setup()  
{  
   // iterate over the pins:
  for(int i = 0;i<8;i++)  
  // initialize the output pins:
  {  
    pinMode(R[i],OUTPUT);  
    pinMode(C[i],OUTPUT);  
  } 
  
}  
  
void loop()  
{  
if(contador == 0){
    Display_special(inicio); 
    contador+=1;                
  }  
 solveNQ(matriz,0);
}

void Display_error(int dat[8][8]){
  for(int i = 0 ; i < 50 ; i++)        //Loop display 100 times 
  {  
  for(int c = 0; c<8;c++)  
  {  
    digitalWrite(C[c],LOW);//use thr column 
    //loop
    for(int r = 0;r<8;r++)  
    {  
      digitalWrite(R[r],dat[r][c]);  
    }  
    delay(1);  
    Clear();  //Remove empty display light
  }
}  
}
void Display_special(int dat[8][8]){
  for(int i = 0 ; i < 1000 ; i++)        //Loop display 100 times 
  {  
  for(int c = 0; c<8;c++)  
  {  
    digitalWrite(C[c],LOW);//use thr column 
    //loop
    for(int r = 0;r<8;r++)  
    {  
      digitalWrite(R[r],dat[r][c]);  
    }  
    delay(1);  
    Clear();  //Remove empty display light
  }
}  
}

void Display(int dat[8][8])    
{  
  for(int i = 0 ; i < 5 ; i++)        //Loop display 100 times 
  {  
  for(int c = 0; c<8;c++)  
  {  
    digitalWrite(C[c],LOW);//use thr column 
    //loop
    for(int r = 0;r<8;r++)  
    {  
      digitalWrite(R[r],dat[r][c]);  
    }  
    delay(1);  
    Clear();  //Remove empty display light
  }
}  
}  
  
void Clear()                          //清空显示  
{  
  for(int i = 0;i<8;i++)  
  {  
    digitalWrite(R[i],LOW);  
    digitalWrite(C[i],HIGH);  
  }
}
      bool solveNQ(int board[8][8], int col) {
        //variables
        int i;

        /*Q
          if all the queens are placed then
          the board is solved
         */
        if(col >= 8) {
            Display(board);/////////////////////////////
            Display_special(fin);
            return true;
        }

        /*
          for the given column col
          try placing the queen in all the
          rows one by one to see if its
          possible to place a queen in the
          given column without dispute
         */
        for(i = 0; i < 8; i++) {
            /*
              check if queen can be placed
              in cell board[i][col]
             */
            if(isSafePos(board, i, col) == true) {
                /*
                  the position is safe
                  so, we place a queen in the
                  cell board[i][col]
                 */
                board[i][col] = 1;
                Display(board);//////////////////////////////////
                
                /*
                  now recursively place rest of
                  the queen
                 */
                if(solveNQ(board, col+1) == true) {
                    return true;
                }

                /*
                  if the queen is placed in cell
                  board[i][col] and it does not
                  leads to a solution then we reset
                  the cell i.e., backtrack
                 */
                Display_error(equis);
                board[i][col] = 0;
                Display(board);//////////////////////////////////
                
            }
        }

        /*
          if queen can&apost be placed in any row
          for the given column col then there is
          no solution
         */
        return false;
    }

    bool isSafePos(int board[8][8], int row, int col) {
        int r, c;

        /*
          this function will check if the position is safe
          for the queen.

          we need to check the rows and the diagonals
         */


        /*
          if there is a queen in the given row
          then it is not a safe position
         */
        for(c = 0; c < col; c++) {
            
             igualar_matrices(ayuda, board);
            if(board[row][c] == 1) {
                ayuda[row][c] = 1;
                Display(ayuda);
                Display_error(choque);
                Display(board);
                return false;
            }
            ayuda[row][c] = 1;
            Display(ayuda);
            Display(board);
        }

        /*
          check upper diagonal
         */
        for(r = row, c = col; r >= 0 && c >= 0; r--, c--) {
            
            igualar_matrices(ayuda, board);
            if(board[r][c] == 1) {
                ayuda[row][c] = 1;
                Display(ayuda);
                Display_error(choque);
                Display(board);
                return false;
            }
            ayuda[row][c] = 1;
            Display(ayuda);
            Display(board);
        }

        /*
          check lower diagonal
         */
        for (r = row, c = col; c >= 0 && r < 8; r++, c--) {
            
            igualar_matrices(ayuda, board);
            if (board[r][c] == 1) {
                ayuda[row][c] = 1;
                Display(ayuda);
                Display_error(choque);
                Display(board);
                return false;
            }
            ayuda[row][c] = 1;
            Display(ayuda);
            Display(board);
        }

        return true;
    }  


void igualar_matrices(int aux[8][8], int aux1[8][8]){
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      aux[i][j] = aux1[i][j] ;
      }
    }
}
