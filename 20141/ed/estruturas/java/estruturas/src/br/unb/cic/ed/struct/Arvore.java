package br.unb.cic.ed.struct;

public class Arvore {
	
	public Arvore() {
	
	}
	
	public Elemento inicializar() {
		
		return null;
		
	}
	
	public boolean estaVazia(Elemento no) {
		
		return (no == null);
		
	}
	
	public Elemento construir(Elemento no) {
		
		Elemento no_a;
		
		if (no == null)
			no_a = null;
		
		else {
			
			no_a = new Elemento(no.getDado());
			no_a.setAnt(construir(no.getAnt()));
			no_a.setProx(construir(no.getProx()));
		
		}
		
		return no_a;
		
	}
	
	public void ler(Elemento no) {
		
		if (no == null)
			System.out.printf(".");
		
		else {
			
			System.out.printf("%c", no.getDado());
			ler(no.getAnt());
			ler(no.getProx());
			
		}
		
	}
	
	public boolean estaBalanceada(Elemento no) {

		if (no == null)
			return true;
		
		if (!estaBalanceada(no.getAnt()))
			return false;
		
		if (!estaBalanceada(no.getProx()))
			return false;
		
		if ((Math.abs(altura(no.getAnt()) - altura(no.getProx()))) > 1)
			return false;

		return true;

	}
	
	public byte altura(Elemento no) {
		
		byte alt_ant, alt_prox;
		
		if (no == null)
			return -1;
		
		else {
			
			alt_ant = altura(no.getAnt());
			alt_prox = altura(no.getProx());
			
			if (alt_ant > alt_prox)
				return ((byte) (1 + alt_ant));
			
			else
				return ((byte) (1 + alt_prox));
			
		}
		
	}
	
	public Elemento rotacionar(Elemento no) {
		
		Elemento no_a;
		Object obj_a;
		
		no_a = no.getProx();
		no.setProx(no.getAnt());
		no.setAnt(no.getProx().getAnt());
		no.getProx().setAnt(no.getProx().getProx());
		no.getProx().setProx(no_a);
		obj_a = no.getDado();
		no.setDado(no.getProx().getDado());
		no.getProx().setDado(obj_a);
		
		return no;
		
	}

}
