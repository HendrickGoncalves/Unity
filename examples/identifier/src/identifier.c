// ----------------------------------------------------------------
// ESPECIFICAÇÃO: O programa deve determinar se um identificador
// é ou não válido. Um identificador válido deve começar com uma
// letra e conter apenas letras ou dígitos. Além disto, deve ter
// no mínimo 1 caractere e no máximo 6 caracteres de comprimento
// ----------------------------------------------------------------

#include "identifier.h"

int valid_s(char ch) {
  if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')))
    return 1;
  else
    return 0;
}

int valid_f(char ch) {
  if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')) || ((ch >= '0') && (ch <= '9')))
    return 1;
  else
    return 0;
}

int identifier(void) {
  char achar;
  int  length, valid_id;
  FILE *fp;

  fp = fopen("src/test_file.txt", "r");

  length = 0;

  achar = fgetc(fp);
  valid_id = valid_s(achar);
  
  if(valid_id) {
    length = 1;
  }

  achar = fgetc(fp);
  while(achar != '\n') {
    if(!(valid_f(achar))) {
      valid_id = 0;
    }
    length++;
    achar = fgetc(fp);
  }

  if (valid_id && (length >= 1) && (length < 6)) {
    fclose(fp);
    return 0;
  } else {
    fclose(fp);
    return 1;
  }
}
