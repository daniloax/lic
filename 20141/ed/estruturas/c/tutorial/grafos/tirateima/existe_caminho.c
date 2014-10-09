int ExisteCaminho (no *p1, no *p2) {                             
arco *pa1;
int achou;

achou = 0;
p1->usado = 1;
pa1 = p1->pacessoarco;
while ((!achou) && (pa1 != NULL)) {
  if (pa1->padj == p2)
    achou = 1;
  else {
    if (!pa1->padj->usado)
      achou = ExisteCaminho (pa1->padj, p2);
    pa1 = pa1->proxarco; 
  }
}
return achou;
}
