package br.unb.cic.ed.struct;

public class Pilha {
	
	public Elemento inicializar() {
		
		return null;
	
	}
	
	public boolean estaVazia(Elemento no) {
		
		return (no == null);
	
	}
	
	public Elemento inserir(Elemento no, Object dado) {
		
		Elemento no_a = new Elemento(dado, no);
		no = no_a;
		
		return no;
		
	}
	
	public Elemento remover(Elemento no) {
		
		Elemento no_a;

		no_a = no;
		no = no_a.getProx();
		no_a = null;
		
		return no;
		
	}
	
	public Object inicio(Elemento no) {
		
		return no.getDado();
		
	}
	
	public void ler(Elemento no) {
		
		Elemento no_a;
		
		if (estaVazia(no))
			System.out.print("fila vazia");
		
		else {
			
			no_a = inicializar();
			
			while (!estaVazia(no)) {
				
				no_a = inserir(no_a, inicio(no));
				System.out.printf("%c\n", inicio(no_a));
				no = remover(no);
				
			}
			
			while (!estaVazia(no_a)) {
				
				no = inserir(no, inicio(no_a));
				no_a = remover(no_a);
			
			}
				
		}
			
	}
	
}
