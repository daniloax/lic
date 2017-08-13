package model;

import java.util.Random;

public class Lista implements Estrutura {
	
	private Elemento no;
	
	public Lista() {

	}
	
	public Elemento getNo() {
		return no;
	}
	
	public void setNo(Elemento no) {
		this.no = no;
	}
	
	public void concatenar(Lista lista_a, Lista lista_b) {
		
		Elemento no_a, no_b, no_c, no_d, no_e, no_f;
		
		no_a = lista_a.getNo();
		no_b = lista_b.getNo();
		
		no_c = null;
		no_d = null;
		
		while ((no_a != null) || (no_b != null)) {
			
			no_e = new Elemento();
			no_f = new Elemento();
			
			if (no_a != null)
				no_e.setDado(no_a.getDado());
				
			if (no_b != null)
				no_f.setDado(no_b.getDado());
			
			if ((no_a != null) && (no_b != null))				
				no_e.setProx(no_f);
			
			if ((no_c == null) && (no_a != null)) {
				
				no_c = no_e;
				no_d = no_c;
			
			} else if ((no_c == null) && (no_b != null)) {
				
				no_c = no_d;
				no_d = no_c;
				
			} else if ((no_c != null) && (no_a != null))				
				no_d.setProx(no_e);
			
			else if ((no_c != null) && (no_b != null))
				no_d.setProx(no_f);
			
			while (no_d.getProx() != null)
				no_d = no_d.getProx();
				
			if (no_a != null)
				no_a = no_a.getProx();
			
			if (no_b != null)
				no_b = no_b.getProx();
			
		}
		
		this.setNo(no_c);
		
	}

	@Override
	public void construir() {
		
		Elemento no_a, no_b;
		Random randomNumbers;
		int valorCaracter;
		
		no_b = new Elemento();
		randomNumbers = new Random();
		
		for (int i = 0; i < 20; i++) {
			
			valorCaracter = 64 + randomNumbers.nextInt(22);
			
			if ((valorCaracter == 65) || (valorCaracter == 69) || (valorCaracter == 73) || (valorCaracter == 79) || (valorCaracter == 85)) {

				no_a = new Elemento((char) valorCaracter, null);
				
				if (this.getNo() == null)
					this.setNo(no_a);
				
				else
					no_b.setProx(no_a);
				
				no_b = no_a;
				
			}				
			
		}
		
		no_b.setProx(null);
	
	}

	@Override
	public void inserir(Object dado) {
		
		Elemento no_a, no_b;
		
		no_a = new Elemento(dado, null);
		
		if (this.getNo() == null)
			this.setNo(no_a);
		
		else {
			
			no_b = this.getNo();
			
			while (no_b.getProx() != null)
				no_b = no_b.getProx();
			
			no_b.setProx(no_a);
				
		}
				
	}
	
	public void ordenar() {
		
		Elemento no_a, no_b;
		Object o;

		if (this.getNo() != null) {
			
			no_a = this.getNo();
			
			while (no_a.getProx() != null) {
			
				no_b = no_a.getProx();
		
				while (no_b != null) {
			
					if ((char) no_a.getDado() > (char) no_b.getDado()) {
						
						o = no_a.getDado();
						no_a.setDado(no_b.getDado());
						no_b.setDado(o);
						
					}
					
					no_b = no_b.getProx();
					
				}
				
				no_a = no_a.getProx();
				
			}
			
		}
		
	}

	@Override
	public boolean procurar(Object dado) {
		
		Elemento no_a;
		boolean flag;
		
		flag = false;
		
		if (this.getNo() == null)
			System.out.printf("lista vazia\n");
		
		else {
			
			no_a = this.getNo();
			
			while ((no_a != null) && !flag) {
				
				if (no_a.getDado() == dado)
					flag = true;
				
				else
					flag = false;
				
				no_a = no_a.getProx();
				
			}
			
			
		}
		
		return flag;
		
	}

	@Override
	public Object raiz() {
		
		if (this.getNo() == null)
			return null;
		
		else
			return this.getNo().getDado();
		
	}

	@Override
	public Object remover() {
		
		Object raiz;
		
		raiz = null;
		
		if (this.getNo().equals(null))
			System.out.printf("lista vazia\n");
		
		else {
			
			raiz = this.getNo().getDado();
			this.setNo(this.getNo().getProx());
			
		}
		
		return raiz;
		
	}

	@Override
	public void remover(Object dado) {
		
		Elemento no_a, no_b;
		boolean flag;
		
		flag = false;
		no_b = new Elemento();
		
		if (this.getNo() == null)
			System.out.printf("lista vazia\n");
		
		else {
			
			no_a = this.getNo();
			
			while (no_a != null) {
				
				if (no_a.getDado().equals(dado)) {
					
					flag = true;
					
					if (this.getNo().getDado().equals(no_a.getDado())) {
						
						no_a = no_a.getProx();
						this.setNo(no_a);
						
					} else {
						
						no_b.setProx(no_a.getProx());
						no_a = no_b.getProx();
						
					}
					
				} else {
					
					no_b = no_a;
					no_a = no_a.getProx();
					
				}
				
			}
			
		}
		
		if (!flag)
			System.out.println("elemento nao presente");
		
		else
			System.out.println("elemento removido");
		
		
	}

	@Override
	public void ler() {
		
		Elemento no_a;
		
		no_a = this.getNo();
		
		if (no_a == null)
			System.out.printf("lista vazia\n");
		
		else {
			
			no_a = this.getNo();
		
			while (no_a != null) {
				
				System.out.printf("%c", no_a.getDado());
				no_a = no_a.getProx();
				
			}
		
		}
		
		System.out.println();
		
	}
	
}
