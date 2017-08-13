arvore *ProcuraComAnt(arvore *ainicio, char chave, arvore **epai) {
  arvore *a1;
  a1 = NULL;
  if (ainicio != NULL) {
    if (ainicio->dado == chave)                             
      a1 = ainicio;
    if (a1 == NULL) {
      *epai = ainicio;
      a1 = ProcuraComAnt (ainicio->esq, chave, epai);
    }  
    if (a1 == NULL){
      *epai = ainicio;           
      a1 = ProcuraComAnt (ainicio->dir, chave, epai);
    }        
  } 
  if (a1 == NULL)
    *epai = NULL;
  return a1;  
} 
