package br.unb.cic.ed.struct;

import java.util.Random;

public class Lista {
	
	public Lista() {

	}
	
	public Elemento construir(Elemento no) {
		
		Elemento no_a, no_b;
		Random randomNumbers;
		int valorCaracter;
		
		no_b = new Elemento();
		randomNumbers = new Random();
		
		for (int i = 0; i < 10; i++) {
			
			valorCaracter = 64 + randomNumbers.nextInt(15);
			
			if ((valorCaracter == 65) || (valorCaracter == 69) || (valorCaracter == 73) || (valorCaracter == 79) || (valorCaracter == 85)) {

				no_a = new Elemento((char) valorCaracter, null);
				
				if (no == null)
					no = no_a;
				
				else
					no_b.setProx(no_a);
				
				no_b = no_a;
				
			}				
			
		}

		return no;
		
	}
	
	public void inserir(Elemento no, Object dado) {
		
		Elemento no_a, no_b;
		
		if (dado instanceof Character)
			dado = (int) ((char) dado);
		
		if (!((int) dado >= 91) || !((int) dado <= 96)) {
			
			no_a = new Elemento((char) ((int) dado), null);
			
			if (no == null)
				no = no_a;
			
			else {
				
				no_b = no;
				
				while (no_b.getProx() != null)
					no_b = no_b.getProx();
				
				no_b.setProx(no_a);
				
			}
			
		}
		
	}

	public void remover(Elemento no, Object dado) {
		
		Elemento no_a, no_b;
		boolean flag;
		
		flag = false;
		no_b = new Elemento();
		
		if (no == null)
			System.out.printf("lista vazia\n");
		
		else {
			
			no_a = no;
			
			while (no_a != null) {
				
				if (no_a.getDado().equals(dado)) {
					
					flag = true;
					
					if (no.equals(no_a)) {
						
						no_a = no_a.getProx();
						no = no_a;
						
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

	public void ler(Elemento no) {
		
		Elemento no_a;
		
		no_a = no;
		
		while (no_a != null) {
			
			System.out.printf("%c", no_a.getDado());
			no_a = no_a.getProx();
			
		}
		
		System.out.println();
		
	}

	public Elemento concatenar(Elemento eno_a, Elemento eno_b) {
		
		Elemento no_a, no_b, no_c, no_d, no_e, no_f;
		
		no_a = eno_a;
		no_b = eno_b;
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
			
			if (no_c == null && no_a != null) {
				
				no_c = no_e;
				no_d = no_c;
			
			} else if (no_c == null && no_b != null) {
				
				no_c = no_f;
				no_d = no_c;
				
			} else if (no_c != null && no_a != null)				
				no_d.setProx(no_e);
			
			else if (no_c != null && no_b != null)
				no_d.setProx(no_f);
			
			while (no_d.getProx() != null)
				no_d = no_d.getProx();
				
			if (no_a != null)
				no_a = no_a.getProx();
			
			if (no_b != null)
				no_b = no_b.getProx();
			
		}
		
		return no_c;
		
	}
	
	public void ordenar(Elemento no) {
		
		Elemento no_a, no_b;
		Object o;

		
		if (no != null) {
			
			no_a = no;
			
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

}
